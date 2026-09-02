// 组件化订阅者
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

namespace composition
{

class ListenerComponent : public rclcpp::Node
{
public:
  explicit ListenerComponent(const rclcpp::NodeOptions & options)
  : Node("listener_component", options)
  {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "chatter", 10, std::bind(&ListenerComponent::on_message, this, _1));
  }

private:
  void on_message(const std_msgs::msg::String::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "收到: '%s'", msg->data.c_str());
  }

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

}  // namespace composition

RCLCPP_COMPONENTS_REGISTER_NODE(composition::ListenerComponent)
