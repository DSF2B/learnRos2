// QoS 订阅者：用参数切换 reliable/best_effort，观察与发布者的兼容性
#include <chrono>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class QosSub : public rclcpp::Node
{
public:
  QosSub() : Node("qos_sub")
  {
    this->declare_parameter<std::string>("reliability", "reliable");

    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "qos_demo", this->make_qos(),
      std::bind(&QosSub::topic_callback, this, _1));

    // 每秒打印收包统计
    timer_ = this->create_wall_timer(1s, [this]() {
      RCLCPP_INFO(this->get_logger(), "累计收到 %d 条", received_);
    });
    RCLCPP_INFO(this->get_logger(), "qos_sub 就绪（reliability=%s）",
      this->get_parameter("reliability").as_string().c_str());
  }

private:
  rclcpp::QoS make_qos() const
  {
    std::string rel = this->get_parameter("reliability").as_string();
    if (rel == "best_effort") {
      return rclcpp::QoS(10).best_effort();
    }
    return rclcpp::QoS(10).reliable();
  }

  void topic_callback(const std_msgs::msg::String::SharedPtr msg)
  {
    received_++;
    RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 3000,
      "收到: '%s'", msg->data.c_str());
  }

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
  rclcpp::TimerBase::SharedPtr timer_;
  int received_{0};
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<QosSub>());
  rclcpp::shutdown();
  return 0;
}
