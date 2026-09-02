// 动态变换发布者：world -> rotor，rotor 绕 Z 轴匀速旋转
#include <chrono>
#include <cmath>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2/LinearMath/Quaternion.h"
#include "geometry_msgs/msg/transform_stamped.hpp"

using namespace std::chrono_literals;

class DynamicTfBroadcaster : public rclcpp::Node
{
public:
  DynamicTfBroadcaster() : Node("dynamic_tf_broadcaster")
  {
    this->declare_parameter<double>("angular_speed", 0.5);   // rad/s

    broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);
    // 100ms 发布一次（TF 变换本质是带时间戳的话题，频率越高延时越小）
    timer_ = this->create_wall_timer(100ms, [this]() { this->timer_callback(); });
    RCLCPP_INFO(this->get_logger(), "动态变换 world -> rotor 发布中...");
  }

private:
  void timer_callback()
  {
    double omega = this->get_parameter("angular_speed").as_double();
    double angle = omega * this->now().seconds();   // 角度随时间线性增长

    geometry_msgs::msg::TransformStamped t;
    t.header.stamp = this->now();
    t.header.frame_id = "world";
    t.child_frame_id = "rotor";
    t.transform.translation.x = 1.0;   // rotor 挂在 world 的 (1,0,0) 处
    t.transform.translation.y = 0.0;
    t.transform.translation.z = 0.0;

    // 欧拉角 (0,0,angle) -> 四元数
    tf2::Quaternion q;
    q.setRPY(0.0, 0.0, angle);
    t.transform.rotation.x = q.x();
    t.transform.rotation.y = q.y();
    t.transform.rotation.z = q.z();
    t.transform.rotation.w = q.w();

    broadcaster_->sendTransform(t);
  }

  std::shared_ptr<tf2_ros::TransformBroadcaster> broadcaster_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DynamicTfBroadcaster>());
  rclcpp::shutdown();
  return 0;
}
