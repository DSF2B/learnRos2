// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ch4_cpp_service:srv/TurtlePatrol.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ch4_cpp_service/srv/detail/turtle_patrol__rosidl_typesupport_introspection_c.h"
#include "ch4_cpp_service/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ch4_cpp_service/srv/detail/turtle_patrol__functions.h"
#include "ch4_cpp_service/srv/detail/turtle_patrol__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ch4_cpp_service__srv__TurtlePatrol_Request__rosidl_typesupport_introspection_c__TurtlePatrol_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ch4_cpp_service__srv__TurtlePatrol_Request__init(message_memory);
}

void ch4_cpp_service__srv__TurtlePatrol_Request__rosidl_typesupport_introspection_c__TurtlePatrol_Request_fini_function(void * message_memory)
{
  ch4_cpp_service__srv__TurtlePatrol_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ch4_cpp_service__srv__TurtlePatrol_Request__rosidl_typesupport_introspection_c__TurtlePatrol_Request_message_member_array[3] = {
  {
    "linear_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ch4_cpp_service__srv__TurtlePatrol_Request, linear_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angular_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ch4_cpp_service__srv__TurtlePatrol_Request, angular_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "duration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ch4_cpp_service__srv__TurtlePatrol_Request, duration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ch4_cpp_service__srv__TurtlePatrol_Request__rosidl_typesupport_introspection_c__TurtlePatrol_Request_message_members = {
  "ch4_cpp_service__srv",  // message namespace
  "TurtlePatrol_Request",  // message name
  3,  // number of fields
  sizeof(ch4_cpp_service__srv__TurtlePatrol_Request),
  ch4_cpp_service__srv__TurtlePatrol_Request__rosidl_typesupport_introspection_c__TurtlePatrol_Request_message_member_array,  // message members
  ch4_cpp_service__srv__TurtlePatrol_Request__rosidl_typesupport_introspection_c__TurtlePatrol_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ch4_cpp_service__srv__TurtlePatrol_Request__rosidl_typesupport_introspection_c__TurtlePatrol_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ch4_cpp_service__srv__TurtlePatrol_Request__rosidl_typesupport_introspection_c__TurtlePatrol_Request_message_type_support_handle = {
  0,
  &ch4_cpp_service__srv__TurtlePatrol_Request__rosidl_typesupport_introspection_c__TurtlePatrol_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ch4_cpp_service
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ch4_cpp_service, srv, TurtlePatrol_Request)() {
  if (!ch4_cpp_service__srv__TurtlePatrol_Request__rosidl_typesupport_introspection_c__TurtlePatrol_Request_message_type_support_handle.typesupport_identifier) {
    ch4_cpp_service__srv__TurtlePatrol_Request__rosidl_typesupport_introspection_c__TurtlePatrol_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ch4_cpp_service__srv__TurtlePatrol_Request__rosidl_typesupport_introspection_c__TurtlePatrol_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "ch4_cpp_service/srv/detail/turtle_patrol__rosidl_typesupport_introspection_c.h"
// already included above
// #include "ch4_cpp_service/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "ch4_cpp_service/srv/detail/turtle_patrol__functions.h"
// already included above
// #include "ch4_cpp_service/srv/detail/turtle_patrol__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ch4_cpp_service__srv__TurtlePatrol_Response__rosidl_typesupport_introspection_c__TurtlePatrol_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ch4_cpp_service__srv__TurtlePatrol_Response__init(message_memory);
}

void ch4_cpp_service__srv__TurtlePatrol_Response__rosidl_typesupport_introspection_c__TurtlePatrol_Response_fini_function(void * message_memory)
{
  ch4_cpp_service__srv__TurtlePatrol_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ch4_cpp_service__srv__TurtlePatrol_Response__rosidl_typesupport_introspection_c__TurtlePatrol_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ch4_cpp_service__srv__TurtlePatrol_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ch4_cpp_service__srv__TurtlePatrol_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ch4_cpp_service__srv__TurtlePatrol_Response__rosidl_typesupport_introspection_c__TurtlePatrol_Response_message_members = {
  "ch4_cpp_service__srv",  // message namespace
  "TurtlePatrol_Response",  // message name
  2,  // number of fields
  sizeof(ch4_cpp_service__srv__TurtlePatrol_Response),
  ch4_cpp_service__srv__TurtlePatrol_Response__rosidl_typesupport_introspection_c__TurtlePatrol_Response_message_member_array,  // message members
  ch4_cpp_service__srv__TurtlePatrol_Response__rosidl_typesupport_introspection_c__TurtlePatrol_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ch4_cpp_service__srv__TurtlePatrol_Response__rosidl_typesupport_introspection_c__TurtlePatrol_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ch4_cpp_service__srv__TurtlePatrol_Response__rosidl_typesupport_introspection_c__TurtlePatrol_Response_message_type_support_handle = {
  0,
  &ch4_cpp_service__srv__TurtlePatrol_Response__rosidl_typesupport_introspection_c__TurtlePatrol_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ch4_cpp_service
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ch4_cpp_service, srv, TurtlePatrol_Response)() {
  if (!ch4_cpp_service__srv__TurtlePatrol_Response__rosidl_typesupport_introspection_c__TurtlePatrol_Response_message_type_support_handle.typesupport_identifier) {
    ch4_cpp_service__srv__TurtlePatrol_Response__rosidl_typesupport_introspection_c__TurtlePatrol_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ch4_cpp_service__srv__TurtlePatrol_Response__rosidl_typesupport_introspection_c__TurtlePatrol_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "ch4_cpp_service/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "ch4_cpp_service/srv/detail/turtle_patrol__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers ch4_cpp_service__srv__detail__turtle_patrol__rosidl_typesupport_introspection_c__TurtlePatrol_service_members = {
  "ch4_cpp_service__srv",  // service namespace
  "TurtlePatrol",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // ch4_cpp_service__srv__detail__turtle_patrol__rosidl_typesupport_introspection_c__TurtlePatrol_Request_message_type_support_handle,
  NULL  // response message
  // ch4_cpp_service__srv__detail__turtle_patrol__rosidl_typesupport_introspection_c__TurtlePatrol_Response_message_type_support_handle
};

static rosidl_service_type_support_t ch4_cpp_service__srv__detail__turtle_patrol__rosidl_typesupport_introspection_c__TurtlePatrol_service_type_support_handle = {
  0,
  &ch4_cpp_service__srv__detail__turtle_patrol__rosidl_typesupport_introspection_c__TurtlePatrol_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ch4_cpp_service, srv, TurtlePatrol_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ch4_cpp_service, srv, TurtlePatrol_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ch4_cpp_service
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ch4_cpp_service, srv, TurtlePatrol)() {
  if (!ch4_cpp_service__srv__detail__turtle_patrol__rosidl_typesupport_introspection_c__TurtlePatrol_service_type_support_handle.typesupport_identifier) {
    ch4_cpp_service__srv__detail__turtle_patrol__rosidl_typesupport_introspection_c__TurtlePatrol_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)ch4_cpp_service__srv__detail__turtle_patrol__rosidl_typesupport_introspection_c__TurtlePatrol_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ch4_cpp_service, srv, TurtlePatrol_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ch4_cpp_service, srv, TurtlePatrol_Response)()->data;
  }

  return &ch4_cpp_service__srv__detail__turtle_patrol__rosidl_typesupport_introspection_c__TurtlePatrol_service_type_support_handle;
}
