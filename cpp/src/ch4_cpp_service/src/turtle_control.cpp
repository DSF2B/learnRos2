#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"
#include "ch4_interfaces/srv/patrol.hpp"
#include "rcl_interfaces/msg/set_parameters_result.hpp"

using SetParametersResult = rcl_interfaces::msg::SetParametersResult;
using Patrol = ch4_interfaces::srv::Patrol;



class TurtleController: public rclcpp::Node
{
public:
   explicit TurtleController(const std::string& node_name):Node(node_name){
      m_velocityPublisher = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
      m_poseSubscription = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose",10,
         std::bind(&TurtleController::onPoseReceived, this,std::placeholders::_1));
      m_targetX=0.0;
      m_targetY=0.0;

      this->declare_parameter("k",1.0);
      this->declare_parameter("maxSpeed",1.0);
      this->get_parameter("k",k);
      this->get_parameter("maxSpeed",maxSpeed);
      m_parameterCallbackHandler = this->add_on_set_parameters_callback(
         [&](const std::vector<rclcpp::Parameter> &parameters)->SetParametersResult{
            SetParametersResult result;
            result.successful = true;
            for(const auto& parameter : parameters){
               RCLCPP_INFO(this->get_logger(),"更新参数的值%s=%f",parameter.get_name().c_str(), parameter.as_double());
               if(parameter.get_name() == "k"){
                  this->k = parameter.as_double();
               }
               else if(parameter.get_name() == "maxSpeed"){
                  this->maxSpeed = parameter.as_double();
               }
            }
            return result;
         });
      m_patrolService = this->create_service<Patrol>("patrol",[&](const Patrol::Request::SharedPtr request,const Patrol::Response::SharedPtr response)->void{
         if((0<request->target_x && 12.0f>request->target_x) && 
         (0<request->target_y && 12.0f>request->target_y))
         {
            this->m_targetX = request->target_x;
            this->m_targetY = request->target_y;
            response->result = Patrol::Response::SUCCESS;
         }
         else
         {
            response->result = Patrol::Response::FAIL;
         }
         
      });
      
   }
private:
   void onPoseReceived(const turtlesim::msg::Pose::SharedPtr pose)
   {
      auto curX=pose->x;
      auto curY=pose->y;
      RCLCPP_INFO(get_logger(),"当前x=%f,y=%f",curX,curY);

      auto dis=std::sqrt((m_targetX-curX)*(m_targetX-curX)+(m_targetY-curY)*(m_targetY-curY));
      auto angle = std::atan2(m_targetY-curY,m_targetX-curX) - pose->theta;
      
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

      m_velocityPublisher->publish(msg);
   }
private:
   float m_targetX;
   float m_targetY;
   double k=1.0;
   double maxSpeed = 3.0;
   rclcpp::Service<Patrol>::SharedPtr m_patrolService;
   OnSetParametersCallbackHandle::SharedPtr m_parameterCallbackHandler;
   rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr m_velocityPublisher;
   rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr m_poseSubscription;

};

int main(int argc,char **argv)
{
   rclcpp::init(argc,argv);
   auto node = std::make_shared<TurtleController>("turtle_controller");
   node->set_parameter(rclcpp::Parameter("k",5.0));
   rclcpp::spin(node);
   rclcpp::shutdown();
   return 0;
}