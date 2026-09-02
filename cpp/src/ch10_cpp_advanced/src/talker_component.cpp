// 组件化节点：与普通节点唯一的区别是注册宏，可被容器动态加载
#include <chrono>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

namespace composition
{

class TalkerComponent : public rclcpp::Node
{
public:
  // 组件构造函数必须接受 NodeOptions（容器加载时传参用）
  explicit TalkerComponent(const rclcpp::NodeOptions & options)
  : Node("talker_component", options), count_(0)
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);
    timer_ = this->create_wall_timer(1s, [this]() {
      auto msg = std_msgs::msg::String();
      msg.data = "composition talker: " + std::to_string(count_++);
      publisher_->publish(msg);
      RCLCPP_INFO(this->get_logger(), "发布: '%s'", msg.data.c_str());
    });
  }

private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  size_t count_;
};

}  // namespace composition

// 注册宏：让 component_container 能按 "composition::TalkerComponent" 找到这个类
RCLCPP_COMPONENTS_REGISTER_NODE(composition::TalkerComponent)
