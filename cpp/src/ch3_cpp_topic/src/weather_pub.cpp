// 自定义消息发布者：发布 ch3_interfaces 包里的 Weather 消息
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "ch3_interfaces/msg/weather.hpp"

using namespace std::chrono_literals;

class WeatherPub : public rclcpp::Node
{
public:
  WeatherPub() : Node("weather_pub")
  {
    publisher_ = this->create_publisher<ch3_interfaces::msg::Weather>("weather", 10);
    timer_ = this->create_wall_timer(2s, [this]() { this->timer_callback(); });
    RCLCPP_INFO(this->get_logger(), "weather_pub 就绪");
  }

private:
  void timer_callback()
  {
    auto msg = ch3_interfaces::msg::Weather();
    msg.temperature = 25.5;
    msg.humidity = 0.62;
    msg.condition = "sunny";
    publisher_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "发布天气: %.1f°C, 湿度 %.0f%%, %s",
      msg.temperature, msg.humidity * 100, msg.condition.c_str());
  }

  rclcpp::Publisher<ch3_interfaces::msg::Weather>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<WeatherPub>());
  rclcpp::shutdown();
  return 0;
}
