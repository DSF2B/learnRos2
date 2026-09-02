// 参数演示节点：声明参数、周期打印、注册参数修改回调（含合法性校验）
#include <chrono>
#include <string>
#include <vector>
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class ParamDemo : public rclcpp::Node
{
public:
  ParamDemo() : Node("param_demo")
  {
    // 声明参数：默认值 + 可选描述。不声明就 get 会抛异常
    this->declare_parameter<std::string>("robot_name", "无名机器人");
    this->declare_parameter<double>("speed", 0.5);
    this->declare_parameter<bool>("enable_log", true);

    // 注册参数修改回调：ros2 param set 触发，可拒绝非法值
    param_callback_handle_ = this->add_on_set_parameters_callback(
      std::bind(&ParamDemo::on_param_change, this, std::placeholders::_1));

    timer_ = this->create_wall_timer(2s, [this]() { this->timer_callback(); });
    RCLCPP_INFO(this->get_logger(), "param_demo 就绪，试试 ros2 param set /param_demo speed 1.0");
  }

private:
  // 参数修改回调：逐个检查新值，返回是否接受
  rcl_interfaces::msg::SetParametersResult on_param_change(
    const std::vector<rclcpp::Parameter> & params)
  {
    rcl_interfaces::msg::SetParametersResult result;
    result.successful = true;

    for (const auto & p : params) {
      if (p.get_name() == "speed" && p.as_double() < 0.0) {
        result.successful = false;
        result.reason = "speed 不能为负数";
        RCLCPP_WARN(this->get_logger(), "拒绝修改: %s", result.reason.c_str());
        return result;   // 任一参数被拒绝，本次修改整体失败
      }
      RCLCPP_INFO(this->get_logger(), "参数 %s = %s",
        p.get_name().c_str(), p.value_to_string().c_str());
    }
    return result;
  }

  void timer_callback()
  {
    if (!this->get_parameter("enable_log").as_bool()) {
      return;
    }
    RCLCPP_INFO(this->get_logger(), "[%s] 当前速度: %.2f m/s",
      this->get_parameter("robot_name").as_string().c_str(),
      this->get_parameter("speed").as_double());
  }

  rclcpp::TimerBase::SharedPtr timer_;
  OnSetParametersCallbackHandle::SharedPtr param_callback_handle_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ParamDemo>());
  rclcpp::shutdown();
  return 0;
}
