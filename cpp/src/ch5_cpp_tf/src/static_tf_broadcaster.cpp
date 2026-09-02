// 静态变换发布者：world -> base_link（固定不动，只发布一次）
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/static_transform_broadcaster.h"
#include "tf2/LinearMath/Quaternion.h"
#include "geometry_msgs/msg/transform_stamped.hpp"

using namespace std::chrono_literals;

class StaticTfBroadcaster : public rclcpp::Node
{
public:
  StaticTfBroadcaster() : Node("static_tf_broadcaster")
  {
    broadcaster_ = std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);
    publish_static_tf();
    RCLCPP_INFO(this->get_logger(), "已发布静态变换 world -> base_link");
  }

private:
  void publish_static_tf()
  {
    geometry_msgs::msg::TransformStamped t;

    t.header.stamp = this->now();
    t.header.frame_id = "world";        // 父坐标系
    t.child_frame_id = "base_link";     // 子坐标系

    // base_link 位于 world 原点上方 0.2m
    t.transform.translation.x = 0.0;
    t.transform.translation.y = 0.0;
    t.transform.translation.z = 0.2;
    t.transform.rotation.x = 0.0;
    t.transform.rotation.y = 0.0;
    t.transform.rotation.z = 0.0;
    t.transform.rotation.w = 1.0;       // 单位四元数 = 无旋转

    // 静态变换只发布一次，之后由 TF 内部 latching 机制保证新监听者也能收到
    broadcaster_->sendTransform(t);
  }

  std::shared_ptr<tf2_ros::StaticTransformBroadcaster> broadcaster_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<StaticTfBroadcaster>());
  rclcpp::shutdown();
  return 0;
}
