// 面向对象风格的节点：继承 rclcpp::Node，成员函数作为回调
#include <chrono>
#include <string>
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class OopNode : public rclcpp::Node
{
public:
  explicit OopNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("oop_node", options)   // 基类构造函数里完成节点初始化
  {
    // 声明参数：默认值 "Hello"，运行时可用 -p greeting:=xxx 覆盖
    this->declare_parameter<std::string>("greeting", "Hello");

    // 定时器：每 500ms 触发一次回调（回调是成员函数）
    timer_ = this->create_wall_timer(
      500ms,
      [this]() { this->timer_callback(); });

    RCLCPP_INFO(this->get_logger(), "oop_node 已启动，问候语: %s",
      this->get_parameter("greeting").as_string().c_str());
  }

private:
  void timer_callback()
  {
    // 每次回调重新读取参数，运行中修改参数会立即生效
    std::string greeting = this->get_parameter("greeting").as_string();
    RCLCPP_INFO(this->get_logger(), "%s, ROS2! 第 %d 次", greeting.c_str(), count_++);
  }

  rclcpp::TimerBase::SharedPtr timer_;
  int count_{0};
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  // 节点用智能指针管理，交由执行器"spin"
  rclcpp::spin(std::make_shared<OopNode>());
  rclcpp::shutdown();
  return 0;
}
