// 机器人底盘驱动节点（仿真版）：
// 订阅 cmd_vel -> PID 调速 -> 一阶惯性电机模型 -> 差速运动学积分 -> 发布里程计/TF/关节状态
// 真机部署时，把"电机模型"换成真实的串口/CAN 通信即可，其余逻辑不变
#include <chrono>
#include <cmath>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "tf2_ros/transform_broadcaster.h"

using namespace std::chrono_literals;
using std::placeholders::_1;

// ============ PID 控制器 ============
class PidController
{
public:
  PidController(double kp, double ki, double kd, double out_max)
  : kp_(kp), ki_(ki), kd_(kd), out_max_(out_max) {}

  // target: 期望值, measured: 实测值, dt: 周期(s)，返回控制输出
  double update(double target, double measured, double dt)
  {
    double error = target - measured;
    integral_ += error * dt;
    double derivative = (error - prev_error_) / dt;
    prev_error_ = error;

    // 积分限幅：防止积分饱和（windup）
    integral_ = std::clamp(integral_, -out_max_ / std::max(ki_, 1e-9), out_max_ / std::max(ki_, 1e-9));

    double out = kp_ * error + ki_ * integral_ + kd_ * derivative;
    return std::clamp(out, -out_max_, out_max_);
  }

  void reset() { integral_ = 0.0; prev_error_ = 0.0; }

private:
  double kp_, ki_, kd_, out_max_;
  double integral_{0.0};
  double prev_error_{0.0};
};

// ============ 底盘驱动节点 ============
class RobotDriver : public rclcpp::Node
{
public:
  RobotDriver() : Node("robot_driver")
  {
    // 机械参数
    this->declare_parameter<double>("wheel_radius", 0.035);
    this->declare_parameter<double>("wheel_separation", 0.24);
    // PID 与电机模型
    this->declare_parameter<double>("kp", 2.0);
    this->declare_parameter<double>("ki", 0.5);
    this->declare_parameter<double>("kd", 0.0);
    this->declare_parameter<double>("motor_tau", 0.2);   // 一阶惯性时间常数（越小响应越快）
    this->declare_parameter<double>("control_rate", 50.0);

    cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "cmd_vel", 10, std::bind(&RobotDriver::cmd_vel_callback, this, _1));
    odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("odom", 10);
    joint_pub_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
    tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);

    double rate = this->get_parameter("control_rate").as_double();
    dt_ = 1.0 / rate;
    int period_ms = static_cast<int>(dt_ * 1000);
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(period_ms), [this]() { this->control_loop(); });

    pid_left_ = PidController(kp(), ki(), kd(), 20.0);
    pid_right_ = PidController(kp(), ki(), kd(), 20.0);

    RCLCPP_INFO(this->get_logger(),
      "robot_driver 就绪（%dHz），用 ros2 topic pub /cmd_vel ... 控制", period_ms);
  }

private:
  void cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr msg)
  {
    // 逆运动学：小车速度 -> 左右轮目标角速度
    double v = msg->linear.x;
    double w = msg->angular.z;
    double r = this->get_parameter("wheel_radius").as_double();
    double d = this->get_parameter("wheel_separation").as_double();
    target_w_l_ = (v - w * d / 2.0) / r;
    target_w_r_ = (v + w * d / 2.0) / r;
  }

  void control_loop()
  {
    // ① PID 计算电机输出（输出量纲 = 轮角速度指令）
    double cmd_l = pid_left_.update(target_w_l_, actual_w_l_, dt_);
    double cmd_r = pid_right_.update(target_w_r_, actual_w_r_, dt_);

    // ② 电机模型：实际转速向指令一阶逼近（真机此步是真实电机响应）
    double tau = this->get_parameter("motor_tau").as_double();
    actual_w_l_ += (cmd_l - actual_w_l_) * dt_ / tau;
    actual_w_r_ += (cmd_r - actual_w_r_) * dt_ / tau;

    // ③ 正运动学：轮速 -> 小车位姿增量
    double r = this->get_parameter("wheel_radius").as_double();
    double d = this->get_parameter("wheel_separation").as_double();
    double v = (actual_w_l_ + actual_w_r_) * r / 2.0;
    double w = (actual_w_r_ - actual_w_l_) * r / d;
    x_ += v * std::cos(theta_) * dt_;
    y_ += v * std::sin(theta_) * dt_;
    theta_ += w * dt_;

    // ④ 发布里程计 + TF + 关节状态
    publish_odom(v, w);
    publish_joint_states();
  }

  void publish_odom(double v, double w)
  {
    auto stamp = this->now();

    // TF: odom -> base_footprint
    geometry_msgs::msg::TransformStamped t;
    t.header.stamp = stamp;
    t.header.frame_id = "odom";
    t.child_frame_id = "base_footprint";
    t.transform.translation.x = x_;
    t.transform.translation.y = y_;
    double half = theta_ / 2.0;   // yaw -> 四元数
    t.transform.rotation.z = std::sin(half);
    t.transform.rotation.w = std::cos(half);
    tf_broadcaster_->sendTransform(t);

    // Odometry 消息：位姿 + 速度 + 协方差（真机要按传感器精度如实填写）
    nav_msgs::msg::Odometry odom;
    odom.header.stamp = stamp;
    odom.header.frame_id = "odom";
    odom.child_frame_id = "base_footprint";
    odom.pose.pose.position.x = x_;
    odom.pose.pose.position.y = y_;
    odom.pose.pose.orientation = t.transform.rotation;
    odom.twist.twist.linear.x = v;
    odom.twist.twist.angular.z = w;
    odom.pose.covariance[0] = 0.01;    // 轮式里程计：位置不确定度随距离累积
    odom.pose.covariance[7] = 0.01;
    odom.pose.covariance[35] = 0.02;
    odom_pub_->publish(odom);
  }

  void publish_joint_states()
  {
    sensor_msgs::msg::JointState js;
    js.header.stamp = this->now();
    js.name = {"left_wheel_joint", "right_wheel_joint"};
    // 轮子转角 = 角速度积分（真机从编码器读取）
    wheel_pos_l_ += actual_w_l_ * dt_;
    wheel_pos_r_ += actual_w_r_ * dt_;
    js.position = {wheel_pos_l_, wheel_pos_r_};
    js.velocity = {actual_w_l_, actual_w_r_};
    joint_pub_->publish(js);
  }

  double kp() { return this->get_parameter("kp").as_double(); }
  double ki() { return this->get_parameter("ki").as_double(); }
  double kd() { return this->get_parameter("kd").as_double(); }

  // 通信
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_pub_;
  std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
  rclcpp::TimerBase::SharedPtr timer_;

  // 状态
  double dt_{0.02};
  double target_w_l_{0.0}, target_w_r_{0.0};   // 目标轮角速度
  double actual_w_l_{0.0}, actual_w_r_{0.0};   // 实际轮角速度
  double x_{0.0}, y_{0.0}, theta_{0.0};        // 里程计位姿
  double wheel_pos_l_{0.0}, wheel_pos_r_{0.0}; // 轮转角
  PidController pid_left_{0.0, 0.0, 0.0, 0.0};
  PidController pid_right_{0.0, 0.0, 0.0, 0.0};
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RobotDriver>());
  rclcpp::shutdown();
  return 0;
}
