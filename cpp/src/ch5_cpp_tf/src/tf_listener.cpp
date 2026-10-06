#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2/LinearMath/Quaternion.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "tf2_ros/transform_listener.hpp"
#include "tf2_ros/buffer.hpp"
#include "tf2/utils.hpp"
#include <chrono>

using namespace std::chrono_literals;
class TFListener : public rclcpp::Node
{
public:
   TFListener():Node("tf_listener")
   {
      m_buffer = std::make_shared<tf2_ros::Buffer>(this->get_clock());
      m_listener=std::make_shared<tf2_ros::TransformListener>(*m_buffer,this);
      m_timer = this->create_wall_timer(2s, std::bind(&TFListener::getTransform, this));
   }
private:
   void getTransform()
   {
      //到buffer查询坐标关系
      try
      {
         const auto transform = m_buffer->lookupTransform("base_link","target_point",this->get_clock()->now(),
            rclcpp::Duration::from_seconds(1.0f));
         //获取查询结果
         auto translation = transform.transform.translation;
         auto rotation =  transform.transform.rotation;
         double y,p,r;
         tf2::getEulerYPR(rotation,y,p,r);
         RCLCPP_INFO(this->get_logger(),"%s平移:%f,%f,%f",transform.header.frame_id.c_str(),translation.x,translation.y,translation.z);
         RCLCPP_INFO(this->get_logger(),"%s旋转:%f,%f,%f",transform.header.frame_id.c_str(),y,p,r);
      }
      catch(const std::exception& e)
      {
         RCLCPP_WARN(this->get_logger(),"%s",e.what());
      }
   }
private:
   //注意:Buffer必须声明在TransformListener之前,析构顺序相反,
   //保证listener先析构,避免其回调访问已销毁的Buffer
   std::shared_ptr<tf2_ros::Buffer> m_buffer;
   std::shared_ptr<tf2_ros::TransformListener> m_listener;
   rclcpp::TimerBase::SharedPtr m_timer;
};

int main(int argc, char** argv)
{
   rclcpp::init(argc,argv);
   auto node = std::make_shared<TFListener>();
   rclcpp::spin(node);
   rclcpp::shutdown();
   return 0;
}