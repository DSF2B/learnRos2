// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ch4_cpp_service:srv/TurtlePatrol.idl
// generated code does not contain a copyright notice

#ifndef CH4_CPP_SERVICE__SRV__DETAIL__TURTLE_PATROL__STRUCT_HPP_
#define CH4_CPP_SERVICE__SRV__DETAIL__TURTLE_PATROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ch4_cpp_service__srv__TurtlePatrol_Request __attribute__((deprecated))
#else
# define DEPRECATED__ch4_cpp_service__srv__TurtlePatrol_Request __declspec(deprecated)
#endif

namespace ch4_cpp_service
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TurtlePatrol_Request_
{
  using Type = TurtlePatrol_Request_<ContainerAllocator>;

  explicit TurtlePatrol_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->linear_x = 0.0;
      this->angular_z = 0.0;
      this->duration = 0.0;
    }
  }

  explicit TurtlePatrol_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->linear_x = 0.0;
      this->angular_z = 0.0;
      this->duration = 0.0;
    }
  }

  // field types and members
  using _linear_x_type =
    double;
  _linear_x_type linear_x;
  using _angular_z_type =
    double;
  _angular_z_type angular_z;
  using _duration_type =
    double;
  _duration_type duration;

  // setters for named parameter idiom
  Type & set__linear_x(
    const double & _arg)
  {
    this->linear_x = _arg;
    return *this;
  }
  Type & set__angular_z(
    const double & _arg)
  {
    this->angular_z = _arg;
    return *this;
  }
  Type & set__duration(
    const double & _arg)
  {
    this->duration = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ch4_cpp_service::srv::TurtlePatrol_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ch4_cpp_service::srv::TurtlePatrol_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ch4_cpp_service::srv::TurtlePatrol_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ch4_cpp_service::srv::TurtlePatrol_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ch4_cpp_service::srv::TurtlePatrol_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ch4_cpp_service::srv::TurtlePatrol_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ch4_cpp_service::srv::TurtlePatrol_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ch4_cpp_service::srv::TurtlePatrol_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ch4_cpp_service::srv::TurtlePatrol_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ch4_cpp_service::srv::TurtlePatrol_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ch4_cpp_service__srv__TurtlePatrol_Request
    std::shared_ptr<ch4_cpp_service::srv::TurtlePatrol_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ch4_cpp_service__srv__TurtlePatrol_Request
    std::shared_ptr<ch4_cpp_service::srv::TurtlePatrol_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TurtlePatrol_Request_ & other) const
  {
    if (this->linear_x != other.linear_x) {
      return false;
    }
    if (this->angular_z != other.angular_z) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    return true;
  }
  bool operator!=(const TurtlePatrol_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TurtlePatrol_Request_

// alias to use template instance with default allocator
using TurtlePatrol_Request =
  ch4_cpp_service::srv::TurtlePatrol_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ch4_cpp_service


#ifndef _WIN32
# define DEPRECATED__ch4_cpp_service__srv__TurtlePatrol_Response __attribute__((deprecated))
#else
# define DEPRECATED__ch4_cpp_service__srv__TurtlePatrol_Response __declspec(deprecated)
#endif

namespace ch4_cpp_service
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TurtlePatrol_Response_
{
  using Type = TurtlePatrol_Response_<ContainerAllocator>;

  explicit TurtlePatrol_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit TurtlePatrol_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ch4_cpp_service::srv::TurtlePatrol_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ch4_cpp_service::srv::TurtlePatrol_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ch4_cpp_service::srv::TurtlePatrol_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ch4_cpp_service::srv::TurtlePatrol_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ch4_cpp_service::srv::TurtlePatrol_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ch4_cpp_service::srv::TurtlePatrol_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ch4_cpp_service::srv::TurtlePatrol_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ch4_cpp_service::srv::TurtlePatrol_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ch4_cpp_service::srv::TurtlePatrol_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ch4_cpp_service::srv::TurtlePatrol_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ch4_cpp_service__srv__TurtlePatrol_Response
    std::shared_ptr<ch4_cpp_service::srv::TurtlePatrol_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ch4_cpp_service__srv__TurtlePatrol_Response
    std::shared_ptr<ch4_cpp_service::srv::TurtlePatrol_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TurtlePatrol_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const TurtlePatrol_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TurtlePatrol_Response_

// alias to use template instance with default allocator
using TurtlePatrol_Response =
  ch4_cpp_service::srv::TurtlePatrol_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ch4_cpp_service

namespace ch4_cpp_service
{

namespace srv
{

struct TurtlePatrol
{
  using Request = ch4_cpp_service::srv::TurtlePatrol_Request;
  using Response = ch4_cpp_service::srv::TurtlePatrol_Response;
};

}  // namespace srv

}  // namespace ch4_cpp_service

#endif  // CH4_CPP_SERVICE__SRV__DETAIL__TURTLE_PATROL__STRUCT_HPP_
