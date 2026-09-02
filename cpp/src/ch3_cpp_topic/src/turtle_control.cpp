#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"
#include <chrono>
#include <cmath>
#include <algorithm>

using namespace std::chrono_literals;

class TurtleCircleNode: public rclcpp::Node
{
public:
   explicit TurtleCircleNode(const std::string& node_name):Node(node_name){
      m_publisher = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
      m_subscription = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose",10,
         std::bind(&TurtleCircleNode::onPoseReceived, this,std::placeholders::_1));
   }
private:
   void onPoseReceived(const turtlesim::msg::Pose::SharedPtr pose)
   {
      auto curX=pose->x;
      auto curY=pose->y;
      RCLCPP_INFO(get_logger(),"当前x=%f,y=%f",curX,curY);

      auto dis=std::sqrt((targetX-curX)*(targetX-curX)+(targetY-curY)*(targetY-curY));
      auto angle = std::atan2(targetY-curY,targetX-curX) - pose->theta;
      
      auto msg=geometry_msgs::msg::Twist();
      if(dis>0.1)
      {
         if(std::fabs(angle)>0.2)
         {
            msg.angular.z=std::fabs(angle);
         }
         else
         {
            msg.linear.x = std::min(k*dis,maxSpeed);
         }
      }

      m_publisher->publish(msg);
   }
   const double targetX =1.0;
   const double targetY=1.0;
   const double k=1.0;
   const double maxSpeed = 3.0;
   rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr m_publisher;
   rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr m_subscription;
};

int main(int argc,char **argv)
{
   rclcpp::init(argc,argv);
   auto node = std::make_shared<TurtleCircleNode>("turtle_control");
   rclcpp::spin(node);
   rclcpp::shutdown();
   return 0;
}