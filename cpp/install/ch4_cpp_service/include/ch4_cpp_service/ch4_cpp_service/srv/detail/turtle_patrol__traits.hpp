// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ch4_cpp_service:srv/TurtlePatrol.idl
// generated code does not contain a copyright notice

#ifndef CH4_CPP_SERVICE__SRV__DETAIL__TURTLE_PATROL__TRAITS_HPP_
#define CH4_CPP_SERVICE__SRV__DETAIL__TURTLE_PATROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ch4_cpp_service/srv/detail/turtle_patrol__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ch4_cpp_service
{

namespace srv
{

inline void to_flow_style_yaml(
  const TurtlePatrol_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: linear_x
  {
    out << "linear_x: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_x, out);
    out << ", ";
  }

  // member: angular_z
  {
    out << "angular_z: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_z, out);
    out << ", ";
  }

  // member: duration
  {
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TurtlePatrol_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: linear_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_x: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_x, out);
    out << "\n";
  }

  // member: angular_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_z: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_z, out);
    out << "\n";
  }

  // member: duration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TurtlePatrol_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ch4_cpp_service

namespace rosidl_generator_traits
{

[[deprecated("use ch4_cpp_service::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ch4_cpp_service::srv::TurtlePatrol_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ch4_cpp_service::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ch4_cpp_service::srv::to_yaml() instead")]]
inline std::string to_yaml(const ch4_cpp_service::srv::TurtlePatrol_Request & msg)
{
  return ch4_cpp_service::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ch4_cpp_service::srv::TurtlePatrol_Request>()
{
  return "ch4_cpp_service::srv::TurtlePatrol_Request";
}

template<>
inline const char * name<ch4_cpp_service::srv::TurtlePatrol_Request>()
{
  return "ch4_cpp_service/srv/TurtlePatrol_Request";
}

template<>
struct has_fixed_size<ch4_cpp_service::srv::TurtlePatrol_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ch4_cpp_service::srv::TurtlePatrol_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ch4_cpp_service::srv::TurtlePatrol_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ch4_cpp_service
{

namespace srv
{

inline void to_flow_style_yaml(
  const TurtlePatrol_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TurtlePatrol_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TurtlePatrol_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ch4_cpp_service

namespace rosidl_generator_traits
{

[[deprecated("use ch4_cpp_service::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ch4_cpp_service::srv::TurtlePatrol_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ch4_cpp_service::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ch4_cpp_service::srv::to_yaml() instead")]]
inline std::string to_yaml(const ch4_cpp_service::srv::TurtlePatrol_Response & msg)
{
  return ch4_cpp_service::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ch4_cpp_service::srv::TurtlePatrol_Response>()
{
  return "ch4_cpp_service::srv::TurtlePatrol_Response";
}

template<>
inline const char * name<ch4_cpp_service::srv::TurtlePatrol_Response>()
{
  return "ch4_cpp_service/srv/TurtlePatrol_Response";
}

template<>
struct has_fixed_size<ch4_cpp_service::srv::TurtlePatrol_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ch4_cpp_service::srv::TurtlePatrol_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ch4_cpp_service::srv::TurtlePatrol_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ch4_cpp_service::srv::TurtlePatrol>()
{
  return "ch4_cpp_service::srv::TurtlePatrol";
}

template<>
inline const char * name<ch4_cpp_service::srv::TurtlePatrol>()
{
  return "ch4_cpp_service/srv/TurtlePatrol";
}

template<>
struct has_fixed_size<ch4_cpp_service::srv::TurtlePatrol>
  : std::integral_constant<
    bool,
    has_fixed_size<ch4_cpp_service::srv::TurtlePatrol_Request>::value &&
    has_fixed_size<ch4_cpp_service::srv::TurtlePatrol_Response>::value
  >
{
};

template<>
struct has_bounded_size<ch4_cpp_service::srv::TurtlePatrol>
  : std::integral_constant<
    bool,
    has_bounded_size<ch4_cpp_service::srv::TurtlePatrol_Request>::value &&
    has_bounded_size<ch4_cpp_service::srv::TurtlePatrol_Response>::value
  >
{
};

template<>
struct is_service<ch4_cpp_service::srv::TurtlePatrol>
  : std::true_type
{
};

template<>
struct is_service_request<ch4_cpp_service::srv::TurtlePatrol_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ch4_cpp_service::srv::TurtlePatrol_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CH4_CPP_SERVICE__SRV__DETAIL__TURTLE_PATROL__TRAITS_HPP_
