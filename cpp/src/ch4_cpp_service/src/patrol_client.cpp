#include "rclcpp/rclcpp.hpp"
#include "ch4_interfaces/srv/patrol.hpp"
#include <ctime>
#include "rcl_interfaces/msg/parameter.hpp"
#include "rcl_interfaces/msg/parameter_value.hpp"
#include "rcl_interfaces/msg/parameter_type.hpp"
#include "rcl_interfaces/srv/set_parameters.hpp"

using Patrol = ch4_interfaces::srv::Patrol;
using SetParam = rcl_interfaces::srv::SetParameters;

class PatrolClient: public rclcpp::Node
{
public:
   explicit PatrolClient(const std::string& node_name):Node(node_name){
      m_patrolClient = this->create_client<Patrol>("patrol");
      srand(time(NULL));
      m_timer = this->create_wall_timer(std::chrono::seconds(5),[&]()->void{
         while(!this->m_patrolClient->wait_for_service(std::chrono::seconds(1))){
            if(!rclcpp::ok()){
               RCLCPP_ERROR(this->get_logger(), "等待服务过程中，rclcpp挂了");
               return ;
            }
            RCLCPP_ERROR(this->get_logger(), "等待patrol服务上线");
         }

         auto request = std::make_shared<Patrol::Request>();
         request->target_x=rand() % 15;
         request->target_y=rand() % 15;
         RCLCPP_INFO(this->get_logger(), "准备好目标点(%f,%f)",
            request->target_x, request->target_y);
         this->m_patrolClient->async_send_request(request,[&](rclcpp::Client<Patrol>::SharedFuture responseFuture)->void{
            auto response = responseFuture.get();
            if(response->result == Patrol::Response::SUCCESS){
               RCLCPP_INFO(this->get_logger(), "请求巡逻目标成功");
            }
            else{
               RCLCPP_INFO(this->get_logger(), "请求巡逻目标失败");
            }
         });
      });
      this->m_paramClient = this->create_client<SetParam>("/turtle_controller/set_parameters");
   }
   void update_param_k(double k){
      auto parameter =  rcl_interfaces::msg::Parameter();
      parameter.name = "k";
      auto parameterValue = rcl_interfaces::msg::ParameterValue();
      parameterValue.type = rcl_interfaces::msg::ParameterType().PARAMETER_DOUBLE;
      parameterValue.double_value = k;
      parameter.value = parameterValue;
      auto request = std::make_shared<SetParam::Request>();
      request->parameters.push_back(parameter);
      auto response = this->call_set_parameters(request);
      if(NULL == response){
         RCLCPP_INFO(this->get_logger(), "参数更新失败");
      }
      for(auto result : response->results){
         if(result.successful == true){
            RCLCPP_INFO(this->get_logger(), "参数更新成功");
         }else{
            RCLCPP_INFO(this->get_logger(), "参数更新失败，原因%s", result.reason.c_str());
         }
      }
   }
private:
   SetParam::Response::SharedPtr call_set_parameters(SetParam::Request::SharedPtr request){
      while(!m_paramClient->wait_for_service(std::chrono::seconds(1))){
         if(!rclcpp::ok()){
            RCLCPP_ERROR(this->get_logger(), "等待服务过程中，rclcpp挂了");
            return nullptr;
         }
         RCLCPP_ERROR(this->get_logger(), "等待patrol服务上线");
         
      }

      auto future = m_paramClient->async_send_request(request);
      rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);
      auto response = future.get();
      return response;
   }

   
private:
   rclcpp::TimerBase::SharedPtr m_timer;
   rclcpp::Client<Patrol>::SharedPtr m_patrolClient;
   rclcpp::Client<SetParam>::SharedPtr m_paramClient;
};

int main(int argc,char **argv)
{
   rclcpp::init(argc,argv);
   auto node = std::make_shared<PatrolClient>("patrol_client");
   node->update_param_k(2.0);
   rclcpp::spin(node);
   rclcpp::shutdown();
   return 0;
}