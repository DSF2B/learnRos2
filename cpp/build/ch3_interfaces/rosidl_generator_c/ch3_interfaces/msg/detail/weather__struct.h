// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ch3_interfaces:msg/Weather.idl
// generated code does not contain a copyright notice

#ifndef CH3_INTERFACES__MSG__DETAIL__WEATHER__STRUCT_H_
#define CH3_INTERFACES__MSG__DETAIL__WEATHER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'condition'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Weather in the package ch3_interfaces.
/**
  * 天气消息：字段类型只支持 ROS 内置类型或其他消息类型
 */
typedef struct ch3_interfaces__msg__Weather
{
  /// 摄氏度
  double temperature;
  /// 相对湿度 0~1
  double humidity;
  /// 天气描述，如 sunny / rainy
  rosidl_runtime_c__String condition;
} ch3_interfaces__msg__Weather;

// Struct for a sequence of ch3_interfaces__msg__Weather.
typedef struct ch3_interfaces__msg__Weather__Sequence
{
  ch3_interfaces__msg__Weather * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ch3_interfaces__msg__Weather__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CH3_INTERFACES__MSG__DETAIL__WEATHER__STRUCT_H_
