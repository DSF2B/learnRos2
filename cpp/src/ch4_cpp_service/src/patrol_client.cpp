// 巡逻客户端：异步调用 turtle_patrol 服务
#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "ch4_cpp_service/srv/turtle_patrol.hpp"

using namespace std::chrono_literals;
using Patrol = ch4_cpp_service::srv::TurtlePatrol;

class PatrolClient : public rclcpp::Node
{
public:
  PatrolClient() : Node("patrol_client")
  {
    // 巡逻指令做成参数，运行时可覆盖
    this->declare_parameter<double>("linear_x", 0.5);
    this->declare_parameter<double>("angular_z", 0.3);
    this->declare_parameter<double>("duration", 2.0);

    client_ = this->create_client<Patrol>("turtle_patrol");
  }

  void send_request()
  {
    // ① 先等服务器上线（服务可能还没启动，最多等 10s）
    while (!client_->wait_for_service(1s)) {
      if (!rclcpp::ok()) {
        RCLCPP_ERROR(this->get_logger(), "客户端被中断");
        return;
      }
      RCLCPP_INFO(this->get_logger(), "等待服务 turtle_patrol 上线...");
    }

    // ② 组装请求
    auto request = std::make_shared<Patrol::Request>();
    request->linear_x = this->get_parameter("linear_x").as_double();
    request->angular_z = this->get_parameter("angular_z").as_double();
    request->duration = this->get_parameter("duration").as_double();

    // ③ 异步调用：不阻塞，应答到达时回调 response_callback
    RCLCPP_INFO(this->get_logger(), "发送巡逻请求: v=%.2f w=%.2f 时长=%.1fs",
      request->linear_x, request->angular_z, request->duration);
    client_->async_send_request(
      request, std::bind(&PatrolClient::response_callback, this,
        std::placeholders::_1));
  }

private:
  void response_callback(rclcpp::Client<Patrol>::SharedFuture future)
  {
    auto response = future.get();
    RCLCPP_INFO(this->get_logger(), "服务应答: success=%d, %s",
      response->success, response->message.c_str());
    rclcpp::shutdown();   // 拿到应答就退出
  }

  rclcpp::Client<Patrol>::SharedPtr client_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<PatrolClient>();
  node->send_request();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
