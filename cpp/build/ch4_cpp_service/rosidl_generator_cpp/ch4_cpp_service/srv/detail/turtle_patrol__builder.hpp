// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ch4_cpp_service:srv/TurtlePatrol.idl
// generated code does not contain a copyright notice

#ifndef CH4_CPP_SERVICE__SRV__DETAIL__TURTLE_PATROL__BUILDER_HPP_
#define CH4_CPP_SERVICE__SRV__DETAIL__TURTLE_PATROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ch4_cpp_service/srv/detail/turtle_patrol__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ch4_cpp_service
{

namespace srv
{

namespace builder
{

class Init_TurtlePatrol_Request_duration
{
public:
  explicit Init_TurtlePatrol_Request_duration(::ch4_cpp_service::srv::TurtlePatrol_Request & msg)
  : msg_(msg)
  {}
  ::ch4_cpp_service::srv::TurtlePatrol_Request duration(::ch4_cpp_service::srv::TurtlePatrol_Request::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ch4_cpp_service::srv::TurtlePatrol_Request msg_;
};

class Init_TurtlePatrol_Request_angular_z
{
public:
  explicit Init_TurtlePatrol_Request_angular_z(::ch4_cpp_service::srv::TurtlePatrol_Request & msg)
  : msg_(msg)
  {}
  Init_TurtlePatrol_Request_duration angular_z(::ch4_cpp_service::srv::TurtlePatrol_Request::_angular_z_type arg)
  {
    msg_.angular_z = std::move(arg);
    return Init_TurtlePatrol_Request_duration(msg_);
  }

private:
  ::ch4_cpp_service::srv::TurtlePatrol_Request msg_;
};

class Init_TurtlePatrol_Request_linear_x
{
public:
  Init_TurtlePatrol_Request_linear_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TurtlePatrol_Request_angular_z linear_x(::ch4_cpp_service::srv::TurtlePatrol_Request::_linear_x_type arg)
  {
    msg_.linear_x = std::move(arg);
    return Init_TurtlePatrol_Request_angular_z(msg_);
  }

private:
  ::ch4_cpp_service::srv::TurtlePatrol_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ch4_cpp_service::srv::TurtlePatrol_Request>()
{
  return ch4_cpp_service::srv::builder::Init_TurtlePatrol_Request_linear_x();
}

}  // namespace ch4_cpp_service


namespace ch4_cpp_service
{

namespace srv
{

namespace builder
{

class Init_TurtlePatrol_Response_message
{
public:
  explicit Init_TurtlePatrol_Response_message(::ch4_cpp_service::srv::TurtlePatrol_Response & msg)
  : msg_(msg)
  {}
  ::ch4_cpp_service::srv::TurtlePatrol_Response message(::ch4_cpp_service::srv::TurtlePatrol_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ch4_cpp_service::srv::TurtlePatrol_Response msg_;
};

class Init_TurtlePatrol_Response_success
{
public:
  Init_TurtlePatrol_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TurtlePatrol_Response_message success(::ch4_cpp_service::srv::TurtlePatrol_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_TurtlePatrol_Response_message(msg_);
  }

private:
  ::ch4_cpp_service::srv::TurtlePatrol_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ch4_cpp_service::srv::TurtlePatrol_Response>()
{
  return ch4_cpp_service::srv::builder::Init_TurtlePatrol_Response_success();
}

}  // namespace ch4_cpp_service

#endif  // CH4_CPP_SERVICE__SRV__DETAIL__TURTLE_PATROL__BUILDER_HPP_
