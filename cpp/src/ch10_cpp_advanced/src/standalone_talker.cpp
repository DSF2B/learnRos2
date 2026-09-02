// 独立运行方式一：直接包含组件源码，当成普通节点跑
#include "talker_component.cpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<composition::TalkerComponent>(rclcpp::NodeOptions()));
  rclcpp::shutdown();
  return 0;
}
