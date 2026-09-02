// 生命周期节点：显式状态机，用 ros2 lifecycle CLI 驱动
// 状态流转：unconfigured -> inactive -> active -> inactive -> unconfigured -> finalized
#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

class LifecycleDemo : public rclcpp_lifecycle::LifecycleNode
{
public:
  LifecycleDemo() : LifecycleNode("lc_demo")
  {
    this->declare_parameter<double>("period_s", 1.0);
    RCLCPP_INFO(this->get_logger(), "创建完成，当前状态: unconfigured");
  }

  // 配置：分配资源（创建发布者/订阅者、读取参数）
  CallbackReturn on_configure(const rclcpp_lifecycle::State &)
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("lc_topic", 10);
    period_ = this->get_parameter("period_s").as_double();
    RCLCPP_INFO(this->get_logger(), "on_configure：资源已分配 -> inactive");
    return CallbackReturn::SUCCESS;
  }

  // 激活：开始干活（启动定时器）。生命周期发布者也要显式激活
  CallbackReturn on_activate(const rclcpp_lifecycle::State &)
  {
    publisher_->on_activate();
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(static_cast<int>(period_ * 1000)),
      [this]() {
        auto msg = std_msgs::msg::String();
        msg.data = "lifecycle active, count: " + std::to_string(count_++);
        publisher_->publish(msg);
      });
    RCLCPP_INFO(this->get_logger(), "on_activate：开始发布 -> active");
    return CallbackReturn::SUCCESS;
  }

  // 停活：暂停干活，保留资源
  CallbackReturn on_deactivate(const rclcpp_lifecycle::State &)
  {
    publisher_->on_deactivate();
    timer_.reset();
    RCLCPP_INFO(this->get_logger(), "on_deactivate：停止发布 -> inactive");
    return CallbackReturn::SUCCESS;
  }

  // 清理：释放资源
  CallbackReturn on_cleanup(const rclcpp_lifecycle::State &)
  {
    publisher_.reset();
    RCLCPP_INFO(this->get_logger(), "on_cleanup：资源已释放 -> unconfigured");
    return CallbackReturn::SUCCESS;
  }

  // 关闭：终态
  CallbackReturn on_shutdown(const rclcpp_lifecycle::State &)
  {
    RCLCPP_INFO(this->get_logger(), "on_shutdown：节点终结 -> finalized");
    return CallbackReturn::SUCCESS;
  }

private:
  rclcpp_lifecycle::LifecyclePublisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  double period_{1.0};
  int count_{0};
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  // 生命周期节点不能直接传给 rclcpp::spin，需通过 executor 挂载节点基接口
  auto node = std::make_shared<LifecycleDemo>();
  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(node->get_node_base_interface());
  executor.spin();
  rclcpp::shutdown();
  return 0;
}
