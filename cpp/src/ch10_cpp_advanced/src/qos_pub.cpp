// QoS 发布者：用参数切换 reliable/best_effort
#include <chrono>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class QosPub : public rclcpp::Node
{
public:
  QosPub() : Node("qos_pub")
  {
    this->declare_parameter<std::string>("reliability", "reliable");

    publisher_ = this->create_publisher<std_msgs::msg::String>("qos_demo", this->make_qos());
    timer_ = this->create_wall_timer(500ms, [this]() {
      auto msg = std_msgs::msg::String();
      msg.data = "count: " + std::to_string(count_++);
      publisher_->publish(msg);
    });
    RCLCPP_INFO(this->get_logger(), "qos_pub 就绪（reliability=%s）",
      this->get_parameter("reliability").as_string().c_str());
  }

private:
  rclcpp::QoS make_qos() const
  {
    std::string rel = this->get_parameter("reliability").as_string();
    if (rel == "best_effort") {
      // 尽力而为：网络不好时允许丢包，追求低延迟
      return rclcpp::QoS(10).best_effort();
    }
    // 可靠：DDS 内部重传，保证送达（默认）
    return rclcpp::QoS(10).reliable();
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  int count_{0};
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<QosPub>());
  rclcpp::shutdown();
  return 0;
}
