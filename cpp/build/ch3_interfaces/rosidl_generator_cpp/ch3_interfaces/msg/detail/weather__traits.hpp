// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ch3_interfaces:msg/Weather.idl
// generated code does not contain a copyright notice

#ifndef CH3_INTERFACES__MSG__DETAIL__WEATHER__TRAITS_HPP_
#define CH3_INTERFACES__MSG__DETAIL__WEATHER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ch3_interfaces/msg/detail/weather__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ch3_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Weather & msg,
  std::ostream & out)
{
  out << "{";
  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << ", ";
  }

  // member: humidity
  {
    out << "humidity: ";
    rosidl_generator_traits::value_to_yaml(msg.humidity, out);
    out << ", ";
  }

  // member: condition
  {
    out << "condition: ";
    rosidl_generator_traits::value_to_yaml(msg.condition, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Weather & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }

  // member: humidity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "humidity: ";
    rosidl_generator_traits::value_to_yaml(msg.humidity, out);
    out << "\n";
  }

  // member: condition
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "condition: ";
    rosidl_generator_traits::value_to_yaml(msg.condition, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Weather & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ch3_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ch3_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ch3_interfaces::msg::Weather & msg,
  std::ostream & out, size_t indentation = 0)
{
  ch3_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ch3_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ch3_interfaces::msg::Weather & msg)
{
  return ch3_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ch3_interfaces::msg::Weather>()
{
  return "ch3_interfaces::msg::Weather";
}

template<>
inline const char * name<ch3_interfaces::msg::Weather>()
{
  return "ch3_interfaces/msg/Weather";
}

template<>
struct has_fixed_size<ch3_interfaces::msg::Weather>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ch3_interfaces::msg::Weather>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ch3_interfaces::msg::Weather>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CH3_INTERFACES__MSG__DETAIL__WEATHER__TRAITS_HPP_
