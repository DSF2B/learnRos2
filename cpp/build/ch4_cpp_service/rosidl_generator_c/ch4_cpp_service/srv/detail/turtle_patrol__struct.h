// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ch4_cpp_service:srv/TurtlePatrol.idl
// generated code does not contain a copyright notice

#ifndef CH4_CPP_SERVICE__SRV__DETAIL__TURTLE_PATROL__STRUCT_H_
#define CH4_CPP_SERVICE__SRV__DETAIL__TURTLE_PATROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/TurtlePatrol in the package ch4_cpp_service.
typedef struct ch4_cpp_service__srv__TurtlePatrol_Request
{
  /// 线速度 (m/s)
  double linear_x;
  /// 角速度 (rad/s)
  double angular_z;
  /// 持续时长 (s)
  double duration;
} ch4_cpp_service__srv__TurtlePatrol_Request;

// Struct for a sequence of ch4_cpp_service__srv__TurtlePatrol_Request.
typedef struct ch4_cpp_service__srv__TurtlePatrol_Request__Sequence
{
  ch4_cpp_service__srv__TurtlePatrol_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ch4_cpp_service__srv__TurtlePatrol_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/TurtlePatrol in the package ch4_cpp_service.
typedef struct ch4_cpp_service__srv__TurtlePatrol_Response
{
  bool success;
  rosidl_runtime_c__String message;
} ch4_cpp_service__srv__TurtlePatrol_Response;

// Struct for a sequence of ch4_cpp_service__srv__TurtlePatrol_Response.
typedef struct ch4_cpp_service__srv__TurtlePatrol_Response__Sequence
{
  ch4_cpp_service__srv__TurtlePatrol_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ch4_cpp_service__srv__TurtlePatrol_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CH4_CPP_SERVICE__SRV__DETAIL__TURTLE_PATROL__STRUCT_H_
