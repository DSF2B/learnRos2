// 话题发布者：每秒向 chatter 话题发布一条字符串消息
#include <chrono>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class Talker : public rclcpp::Node
{
public:
  Talker() : Node("talker"), count_(0)
  {
    // 创建发布者：<消息类型>(话题名, 队列深度)
    publisher_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);

    // 定时器驱动发布节奏
    timer_ = this->create_wall_timer(1s, [this]() { this->timer_callback(); });
    RCLCPP_INFO(this->get_logger(), "talker 就绪，开始发布 chatter");
  }

private:
  void timer_callback()
  {
    auto msg = std_msgs::msg::String();
    msg.data = "Hello ROS2 topic, count: " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "发布: '%s'", msg.data.c_str());
    publisher_->publish(msg);   // 发布！
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  size_t count_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Talker>());
  rclcpp::shutdown();
  return 0;
}
