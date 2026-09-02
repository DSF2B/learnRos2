// TF 监听者：每秒查询 world -> rotor 的变换并打印
#include <chrono>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
// 四元数与 geometry_msgs 的转换是纯头文件实现，必须显式包含，
// 否则 tf2::fromMsg / tf2::getEulerYPR 会链接失败
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "tf2/utils.h"

using namespace std::chrono_literals;

class TfListener : public rclcpp::Node
{
public:
  TfListener() : Node("tf_listener")
  {
    // Buffer 缓存收到的 TF 数据，Listener 负责订阅 /tf 和 /tf_static
    tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    timer_ = this->create_wall_timer(1s, [this]() { this->timer_callback(); });
    RCLCPP_INFO(this->get_logger(), "tf_listener 就绪，等待 world -> rotor...");
  }

private:
  void timer_callback()
  {
    try {
      // 查询最新可用变换；抛出异常则说明变换不存在或数据过期
      auto t = tf_buffer_->lookupTransform(
        "world", "rotor", tf2::TimePointZero);

      // 四元数 -> 欧拉角
      double roll = 0.0, pitch = 0.0, yaw = 0.0;
      tf2::getEulerYPR(t.transform.rotation, yaw, pitch, roll);

      RCLCPP_INFO(this->get_logger(),
        "rotor 位置: (%.2f, %.2f, %.2f), 朝向 yaw=%.2f°",
        t.transform.translation.x,
        t.transform.translation.y,
        t.transform.translation.z,
        yaw * 180.0 / M_PI);
    } catch (const tf2::TransformException & ex) {
      RCLCPP_WARN(this->get_logger(), "查询失败: %s", ex.what());
    }
  }

  std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
  std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TfListener>());
  rclcpp::shutdown();
  return 0;
}
