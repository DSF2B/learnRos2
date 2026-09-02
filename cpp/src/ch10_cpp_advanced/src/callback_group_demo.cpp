// 回调组演示：一个"慢回调"（模拟耗时处理）不再拖垮其他回调
// 关键：慢回调单独放一个 MutuallyExclusive 组 + 多线程执行器
#include <chrono>
#include <thread>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class CallbackGroupDemo : public rclcpp::Node
{
public:
  CallbackGroupDemo() : Node("callback_group_demo")
  {
    // 两个回调组：慢回调独占一组，快回调用另一组
    slow_group_ = this->create_callback_group(
      rclcpp::CallbackGroupType::MutuallyExclusive);
    fast_group_ = this->create_callback_group(
      rclcpp::CallbackGroupType::MutuallyExclusive);

    // 发布者：每 500ms 同时发两个话题（自给自足的演示）
    pub_slow_ = this->create_publisher<std_msgs::msg::Int32>("slow_topic", 10);
    pub_fast_ = this->create_publisher<std_msgs::msg::Int32>("fast_topic", 10);
    timer_ = this->create_wall_timer(500ms, [this]() {
      auto msg = std_msgs::msg::Int32();
      msg.data = counter_;
      pub_slow_->publish(msg);
      pub_fast_->publish(msg);
      counter_++;
    });

    // 订阅者：显式指定各自的回调组
    rclcpp::SubscriptionOptions slow_options;
    slow_options.callback_group = slow_group_;
    sub_slow_ = this->create_subscription<std_msgs::msg::Int32>(
      "slow_topic", 10,
      std::bind(&CallbackGroupDemo::slow_callback, this, _1), slow_options);

    rclcpp::SubscriptionOptions fast_options;
    fast_options.callback_group = fast_group_;
    sub_fast_ = this->create_subscription<std_msgs::msg::Int32>(
      "fast_topic", 10,
      std::bind(&CallbackGroupDemo::fast_callback, this, _1), fast_options);

    RCLCPP_INFO(this->get_logger(), "慢回调(2s)与快回调分组运行，观察快回调不被阻塞");
  }

private:
  void slow_callback(const std_msgs::msg::Int32::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "慢回调开始处理 #%d（耗时 2s）...", msg->data);
    std::this_thread::sleep_for(2s);   // 模拟图像处理等耗时任务
    RCLCPP_INFO(this->get_logger(), "慢回调 #%d 完成", msg->data);
  }

  void fast_callback(const std_msgs::msg::Int32::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "快回调收到 #%d（立即返回）", msg->data);
  }

  rclcpp::CallbackGroup::SharedPtr slow_group_;
  rclcpp::CallbackGroup::SharedPtr fast_group_;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr pub_slow_;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr pub_fast_;
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub_slow_;
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub_fast_;
  rclcpp::TimerBase::SharedPtr timer_;
  int counter_{0};
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<CallbackGroupDemo>();
  // 两个线程的执行器：两组回调可以并行
  rclcpp::executors::MultiThreadedExecutor executor(rclcpp::ExecutorOptions(), 2);
  executor.add_node(node);
  executor.spin();
  rclcpp::shutdown();
  return 0;
}
