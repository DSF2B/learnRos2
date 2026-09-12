#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2/LinearMath/Quaternion.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "tf2_ros/static_transform_broadcaster.hpp"

class StaticTFBroadcaster : public rclcpp::Node
{
public:
   StaticTFBroadcaster():Node("static_tf_broadcaster")
   {
      this->m_broadcaster = std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);
      this->public_tf();
   }
private:
   void public_tf()
   {
      geometry_msgs::msg::TransformStamped transform;
      transform.header.stamp = this->get_clock()->now();
      transform.header.frame_id = "map";
      transform.child_frame_id = "target_point";
      transform.transform.translation.x = 5.0;
      transform.transform.translation.y = 3.0;
      transform.transform.translation.z = 0.0;
      tf2::Quaternion q;
      q.setRPY(0.0,0.0,50/180.0*M_PI);
      transform.transform.rotation = tf2::toMsg(q);
      this->m_broadcaster->sendTransform(transform);
   }
private:
   std::shared_ptr<tf2_ros::StaticTransformBroadcaster> m_broadcaster;
};

int main(int argc, char** argv)
{
   rclcpp::init(argc,argv);
   auto node = std::make_shared<StaticTFBroadcaster>();
   rclcpp::spin(node);
   rclcpp::shutdown();
   return 0;
}