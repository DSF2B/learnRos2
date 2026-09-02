// 自定义消息订阅者：接收 Weather 消息
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "ch3_interfaces/msg/weather.hpp"

using std::placeholders::_1;

class WeatherSub : public rclcpp::Node
{
public:
  WeatherSub() : Node("weather_sub")
  {
    subscription_ = this->create_subscription<ch3_interfaces::msg::Weather>(
      "weather", 10, std::bind(&WeatherSub::topic_callback, this, _1));
    RCLCPP_INFO(this->get_logger(), "weather_sub 就绪，等待天气消息...");
  }

private:
  void topic_callback(const ch3_interfaces::msg::Weather::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "天气: %.1f°C, 湿度 %.0f%%, %s",
      msg->temperature, msg->humidity * 100, msg->condition.c_str());
  }

  rclcpp::Subscription<ch3_interfaces::msg::Weather>::SharedPtr subscription_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<WeatherSub>());
  rclcpp::shutdown();
  return 0;
}
