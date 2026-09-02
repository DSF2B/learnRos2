#include <QApplication>
#include <QLabel>
#include <QString>
#include "rclcpp/rclcpp.hpp"
#include "ch3_status_interfaces/msg/system_status.hpp"
#include <sstream>
#include <thread>
#include <memory>

using SystemStatus = ch3_status_interfaces::msg::SystemStatus;

class SystemStatusDisplay: public rclcpp::Node
{
public:
   SystemStatusDisplay(std::string node_name):Node(node_name)
   {
      m_label = new QLabel();
      m_label->setText(getQStringFromMsg(std::make_shared<SystemStatus>()));
      m_label->show();
      
      m_subscriber=this->create_subscription<SystemStatus>("sys_status",10,[&](
         const SystemStatus::SharedPtr msg)->void{
         m_label->setText(getQStringFromMsg(msg));
      });
   }
private:
   QString getQStringFromMsg(SystemStatus::SharedPtr msg);
   rclcpp::Subscription<SystemStatus>::SharedPtr m_subscriber;
   QLabel *m_label;
   
};

QString SystemStatusDisplay::getQStringFromMsg(SystemStatus::SharedPtr msg)
{
      std::stringstream showStr;
      showStr<<"=========系统状态=========\n"<<
      "数据时间:\t"<<msg->stamp.sec<<"\t\n"<<
      "主机名称:\t"<<msg->host_name<<"\t\n"<<
      "CPU使用率:\t"<<msg->cpu_percent<<"\t\n"<<
      "内存使用率:\t"<<msg->memory_percent<<"\t\n"<<
      "可用内存:\t"<<msg->memory_available<<"\t\n"<<
      "内存总大小:\t"<<msg->memory_total<<"\t\n"<<
      "网络发送数据总量:\t"<<msg->net_sent<<"\tMB\n"<<
      "网络接收数据总量:\t"<<msg->net_recv<<"\tMB\n"<<
      "=========系统状态=========";
      return QString::fromStdString(showStr.str());
      
}

int main(int argc,char** argv)
{
   rclcpp::init(argc,argv);
   QApplication app(argc,argv);
   auto node=std::make_shared<SystemStatusDisplay>("sys_status_display");
   std::thread([&]()->void{
      rclcpp::spin(node);
   }).detach();
   app.exec();
   rclcpp::shutdown();
   return 0;
}