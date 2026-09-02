// 独立运行方式二：手动组合——一个进程、一个执行器、多个节点
// 好处：同一进程内话题走 intra-process（零拷贝），省内存省线程
#include "talker_component.cpp"
#include "listener_component.cpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  auto exec = std::make_shared<rclcpp::executors::SingleThreadedExecutor>();

  auto talker = std::make_shared<composition::TalkerComponent>(rclcpp::NodeOptions());
  auto listener = std::make_shared<composition::ListenerComponent>(rclcpp::NodeOptions());

  exec->add_node(talker);
  exec->add_node(listener);
  exec->spin();

  rclcpp::shutdown();
  return 0;
}
