// 巡逻服务端：收到巡逻请求后控制海龟运动，到时自动停止
#include <chrono>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "ch4_cpp_service/srv/turtle_patrol.hpp"

using namespace std::chrono_literals;
using Patrol = ch4_cpp_service::srv::TurtlePatrol;

class PatrolServer : public rclcpp::Node
{
public:
  PatrolServer() : Node("patrol_server")
  {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);

    // 创建服务端：<srv类型>(服务名, 请求处理回调)
    service_ = this->create_service<Patrol>(
      "turtle_patrol",
      std::bind(&PatrolServer::handle_patrol, this,
        std::placeholders::_1, std::placeholders::_2));

    // 100ms 检查一次巡逻是否到期（用定时器而不是 sleep，避免阻塞服务回调）
    check_timer_ = this->create_wall_timer(
      100ms, [this]() { this->stop_if_expired(); });

    RCLCPP_INFO(this->get_logger(), "patrol_server 就绪，服务: turtle_patrol");
  }

private:
  void handle_patrol(
    const std::shared_ptr<Patrol::Request> request,
    std::shared_ptr<Patrol::Response> response)
  {
    auto cmd = geometry_msgs::msg::Twist();
    cmd.linear.x = request->linear_x;
    cmd.angular.z = request->angular_z;
    publisher_->publish(cmd);

    // 记录停止时刻，由定时器到时停止
    patrol_end_ = this->now() + rclcpp::Duration::from_seconds(request->duration);

    RCLCPP_INFO(this->get_logger(), "收到巡逻请求: v=%.2f w=%.2f 时长=%.1fs",
      request->linear_x, request->angular_z, request->duration);

    response->success = true;
    response->message =
      "开始巡逻，" + std::to_string(request->duration) + " 秒后自动停止";
  }

  void stop_if_expired()
  {
    // 没有进行中的巡逻（用零时间作哨兵值）
    if (patrol_end_.nanoseconds() == 0) {
      return;
    }
    if (this->now() >= patrol_end_) {
      publisher_->publish(geometry_msgs::msg::Twist());   // 全零 = 停止
      RCLCPP_INFO(this->get_logger(), "巡逻结束，海龟已停止");
      patrol_end_ = rclcpp::Time(0, 0, RCL_ROS_TIME);
    }
  }

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::Service<Patrol>::SharedPtr service_;
  rclcpp::TimerBase::SharedPtr check_timer_;
  rclcpp::Time patrol_end_{0, 0, RCL_ROS_TIME};
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PatrolServer>());
  rclcpp::shutdown();
  return 0;
}
