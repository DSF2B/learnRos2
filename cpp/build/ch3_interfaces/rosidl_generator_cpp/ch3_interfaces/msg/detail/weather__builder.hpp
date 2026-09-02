// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ch3_interfaces:msg/Weather.idl
// generated code does not contain a copyright notice

#ifndef CH3_INTERFACES__MSG__DETAIL__WEATHER__BUILDER_HPP_
#define CH3_INTERFACES__MSG__DETAIL__WEATHER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ch3_interfaces/msg/detail/weather__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ch3_interfaces
{

namespace msg
{

namespace builder
{

class Init_Weather_condition
{
public:
  explicit Init_Weather_condition(::ch3_interfaces::msg::Weather & msg)
  : msg_(msg)
  {}
  ::ch3_interfaces::msg::Weather condition(::ch3_interfaces::msg::Weather::_condition_type arg)
  {
    msg_.condition = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ch3_interfaces::msg::Weather msg_;
};

class Init_Weather_humidity
{
public:
  explicit Init_Weather_humidity(::ch3_interfaces::msg::Weather & msg)
  : msg_(msg)
  {}
  Init_Weather_condition humidity(::ch3_interfaces::msg::Weather::_humidity_type arg)
  {
    msg_.humidity = std::move(arg);
    return Init_Weather_condition(msg_);
  }

private:
  ::ch3_interfaces::msg::Weather msg_;
};

class Init_Weather_temperature
{
public:
  Init_Weather_temperature()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Weather_humidity temperature(::ch3_interfaces::msg::Weather::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_Weather_humidity(msg_);
  }

private:
  ::ch3_interfaces::msg::Weather msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ch3_interfaces::msg::Weather>()
{
  return ch3_interfaces::msg::builder::Init_Weather_temperature();
}

}  // namespace ch3_interfaces

#endif  // CH3_INTERFACES__MSG__DETAIL__WEATHER__BUILDER_HPP_
