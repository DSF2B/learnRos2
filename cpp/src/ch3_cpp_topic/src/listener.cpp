// 话题订阅者：接收 chatter 话题消息并打印
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class Listener : public rclcpp::Node
{
public:
  Listener() : Node("listener")
  {
    // 创建订阅者：<消息类型>(话题名, 队列深度, 回调函数)
    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "chatter", 10,
      std::bind(&Listener::topic_callback, this, _1));
    RCLCPP_INFO(this->get_logger(), "listener 就绪，等待 chatter 消息...");
  }

private:
  // 回调签名：共享指针指向收到的消息
  void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "收到: '%s'", msg->data.c_str());
  }

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Listener>());
  rclcpp::shutdown();
  return 0;
}
