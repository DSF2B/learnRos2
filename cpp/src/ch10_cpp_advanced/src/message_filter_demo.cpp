// 消息过滤器：把两个话题按时间戳配对（多传感器时间同步）
// 模拟：气压计(海拔) + 温度计(温度) 同步采样，融合输出
#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/float64.hpp"
#include "message_filters/subscriber.h"
#include "message_filters/time_synchronizer.h"

using namespace std::chrono_literals;

class MessageFilterDemo : public rclcpp::Node
{
public:
  MessageFilterDemo() : Node("message_filter_demo")
  {
    // 两个"传感器"：同一定时器、同一时间戳发布
    alt_pub_ = this->create_publisher<std_msgs::msg::Int32>("altitude", 10);
    temp_pub_ = this->create_publisher<std_msgs::msg::Float64>("temperature", 10);
    timer_ = this->create_wall_timer(500ms, [this]() {
      auto alt = std_msgs::msg::Int32();
      auto temp = std_msgs::msg::Float64();
      alt.data = altitude_++;
      temp.data = 25.0 + 0.1 * altitude_;
      alt_pub_->publish(alt);
      temp_pub_->publish(temp);
    });

    // message_filters 订阅者（替代普通订阅）+ 时间同步器
    alt_sub_.subscribe(this, "altitude");
    temp_sub_.subscribe(this, "temperature");
    sync_ = std::make_shared<message_filters::TimeSynchronizer<
        std_msgs::msg::Int32, std_msgs::msg::Float64>>(alt_sub_, temp_sub_, 10);
    sync_->registerCallback(
      std::bind(&MessageFilterDemo::synced_callback, this,
        std::placeholders::_1, std::placeholders::_2));
    RCLCPP_INFO(this->get_logger(), "时间同步就绪，等待配对的传感器数据...");
  }

private:
  void synced_callback(
    const std_msgs::msg::Int32::ConstSharedPtr alt,
    const std_msgs::msg::Float64::ConstSharedPtr temp)
  {
    RCLCPP_INFO(this->get_logger(), "同步数据: 海拔 %dm -> 温度 %.1f°C",
      alt->data, temp->data);
  }

  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr alt_pub_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr temp_pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  int altitude_{0};

  message_filters::Subscriber<std_msgs::msg::Int32> alt_sub_;
  message_filters::Subscriber<std_msgs::msg::Float64> temp_sub_;
  std::shared_ptr<message_filters::TimeSynchronizer<
      std_msgs::msg::Int32, std_msgs::msg::Float64>> sync_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MessageFilterDemo>());
  rclcpp::shutdown();
  return 0;
}
