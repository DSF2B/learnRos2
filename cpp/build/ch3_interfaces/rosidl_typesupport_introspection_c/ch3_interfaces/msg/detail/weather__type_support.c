// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ch3_interfaces:msg/Weather.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ch3_interfaces/msg/detail/weather__rosidl_typesupport_introspection_c.h"
#include "ch3_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ch3_interfaces/msg/detail/weather__functions.h"
#include "ch3_interfaces/msg/detail/weather__struct.h"


// Include directives for member types
// Member `condition`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ch3_interfaces__msg__Weather__rosidl_typesupport_introspection_c__Weather_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ch3_interfaces__msg__Weather__init(message_memory);
}

void ch3_interfaces__msg__Weather__rosidl_typesupport_introspection_c__Weather_fini_function(void * message_memory)
{
  ch3_interfaces__msg__Weather__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ch3_interfaces__msg__Weather__rosidl_typesupport_introspection_c__Weather_message_member_array[3] = {
  {
    "temperature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ch3_interfaces__msg__Weather, temperature),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "humidity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ch3_interfaces__msg__Weather, humidity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "condition",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ch3_interfaces__msg__Weather, condition),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ch3_interfaces__msg__Weather__rosidl_typesupport_introspection_c__Weather_message_members = {
  "ch3_interfaces__msg",  // message namespace
  "Weather",  // message name
  3,  // number of fields
  sizeof(ch3_interfaces__msg__Weather),
  ch3_interfaces__msg__Weather__rosidl_typesupport_introspection_c__Weather_message_member_array,  // message members
  ch3_interfaces__msg__Weather__rosidl_typesupport_introspection_c__Weather_init_function,  // function to initialize message memory (memory has to be allocated)
  ch3_interfaces__msg__Weather__rosidl_typesupport_introspection_c__Weather_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ch3_interfaces__msg__Weather__rosidl_typesupport_introspection_c__Weather_message_type_support_handle = {
  0,
  &ch3_interfaces__msg__Weather__rosidl_typesupport_introspection_c__Weather_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ch3_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ch3_interfaces, msg, Weather)() {
  if (!ch3_interfaces__msg__Weather__rosidl_typesupport_introspection_c__Weather_message_type_support_handle.typesupport_identifier) {
    ch3_interfaces__msg__Weather__rosidl_typesupport_introspection_c__Weather_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ch3_interfaces__msg__Weather__rosidl_typesupport_introspection_c__Weather_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
