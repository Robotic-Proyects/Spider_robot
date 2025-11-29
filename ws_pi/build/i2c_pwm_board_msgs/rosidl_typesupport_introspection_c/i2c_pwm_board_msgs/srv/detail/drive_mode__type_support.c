// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from i2c_pwm_board_msgs:srv/DriveMode.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "i2c_pwm_board_msgs/srv/detail/drive_mode__rosidl_typesupport_introspection_c.h"
#include "i2c_pwm_board_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "i2c_pwm_board_msgs/srv/detail/drive_mode__functions.h"
#include "i2c_pwm_board_msgs/srv/detail/drive_mode__struct.h"


// Include directives for member types
// Member `mode`
#include "rosidl_runtime_c/string_functions.h"
// Member `servos`
#include "i2c_pwm_board_msgs/msg/position.h"
// Member `servos`
#include "i2c_pwm_board_msgs/msg/detail/position__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__DriveMode_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  i2c_pwm_board_msgs__srv__DriveMode_Request__init(message_memory);
}

void i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__DriveMode_Request_fini_function(void * message_memory)
{
  i2c_pwm_board_msgs__srv__DriveMode_Request__fini(message_memory);
}

size_t i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__size_function__DriveMode_Request__servos(
  const void * untyped_member)
{
  const i2c_pwm_board_msgs__msg__Position__Sequence * member =
    (const i2c_pwm_board_msgs__msg__Position__Sequence *)(untyped_member);
  return member->size;
}

const void * i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__get_const_function__DriveMode_Request__servos(
  const void * untyped_member, size_t index)
{
  const i2c_pwm_board_msgs__msg__Position__Sequence * member =
    (const i2c_pwm_board_msgs__msg__Position__Sequence *)(untyped_member);
  return &member->data[index];
}

void * i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__get_function__DriveMode_Request__servos(
  void * untyped_member, size_t index)
{
  i2c_pwm_board_msgs__msg__Position__Sequence * member =
    (i2c_pwm_board_msgs__msg__Position__Sequence *)(untyped_member);
  return &member->data[index];
}

void i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__fetch_function__DriveMode_Request__servos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const i2c_pwm_board_msgs__msg__Position * item =
    ((const i2c_pwm_board_msgs__msg__Position *)
    i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__get_const_function__DriveMode_Request__servos(untyped_member, index));
  i2c_pwm_board_msgs__msg__Position * value =
    (i2c_pwm_board_msgs__msg__Position *)(untyped_value);
  *value = *item;
}

void i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__assign_function__DriveMode_Request__servos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  i2c_pwm_board_msgs__msg__Position * item =
    ((i2c_pwm_board_msgs__msg__Position *)
    i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__get_function__DriveMode_Request__servos(untyped_member, index));
  const i2c_pwm_board_msgs__msg__Position * value =
    (const i2c_pwm_board_msgs__msg__Position *)(untyped_value);
  *item = *value;
}

bool i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__resize_function__DriveMode_Request__servos(
  void * untyped_member, size_t size)
{
  i2c_pwm_board_msgs__msg__Position__Sequence * member =
    (i2c_pwm_board_msgs__msg__Position__Sequence *)(untyped_member);
  i2c_pwm_board_msgs__msg__Position__Sequence__fini(member);
  return i2c_pwm_board_msgs__msg__Position__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__DriveMode_Request_message_member_array[6] = {
  {
    "mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i2c_pwm_board_msgs__srv__DriveMode_Request, mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rpm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i2c_pwm_board_msgs__srv__DriveMode_Request, rpm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "radius",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i2c_pwm_board_msgs__srv__DriveMode_Request, radius),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "track",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i2c_pwm_board_msgs__srv__DriveMode_Request, track),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "scale",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i2c_pwm_board_msgs__srv__DriveMode_Request, scale),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "servos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i2c_pwm_board_msgs__srv__DriveMode_Request, servos),  // bytes offset in struct
    NULL,  // default value
    i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__size_function__DriveMode_Request__servos,  // size() function pointer
    i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__get_const_function__DriveMode_Request__servos,  // get_const(index) function pointer
    i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__get_function__DriveMode_Request__servos,  // get(index) function pointer
    i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__fetch_function__DriveMode_Request__servos,  // fetch(index, &value) function pointer
    i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__assign_function__DriveMode_Request__servos,  // assign(index, value) function pointer
    i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__resize_function__DriveMode_Request__servos  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__DriveMode_Request_message_members = {
  "i2c_pwm_board_msgs__srv",  // message namespace
  "DriveMode_Request",  // message name
  6,  // number of fields
  sizeof(i2c_pwm_board_msgs__srv__DriveMode_Request),
  i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__DriveMode_Request_message_member_array,  // message members
  i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__DriveMode_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__DriveMode_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__DriveMode_Request_message_type_support_handle = {
  0,
  &i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__DriveMode_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_i2c_pwm_board_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i2c_pwm_board_msgs, srv, DriveMode_Request)() {
  i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__DriveMode_Request_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i2c_pwm_board_msgs, msg, Position)();
  if (!i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__DriveMode_Request_message_type_support_handle.typesupport_identifier) {
    i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__DriveMode_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &i2c_pwm_board_msgs__srv__DriveMode_Request__rosidl_typesupport_introspection_c__DriveMode_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "i2c_pwm_board_msgs/srv/detail/drive_mode__rosidl_typesupport_introspection_c.h"
// already included above
// #include "i2c_pwm_board_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "i2c_pwm_board_msgs/srv/detail/drive_mode__functions.h"
// already included above
// #include "i2c_pwm_board_msgs/srv/detail/drive_mode__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void i2c_pwm_board_msgs__srv__DriveMode_Response__rosidl_typesupport_introspection_c__DriveMode_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  i2c_pwm_board_msgs__srv__DriveMode_Response__init(message_memory);
}

void i2c_pwm_board_msgs__srv__DriveMode_Response__rosidl_typesupport_introspection_c__DriveMode_Response_fini_function(void * message_memory)
{
  i2c_pwm_board_msgs__srv__DriveMode_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember i2c_pwm_board_msgs__srv__DriveMode_Response__rosidl_typesupport_introspection_c__DriveMode_Response_message_member_array[1] = {
  {
    "error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i2c_pwm_board_msgs__srv__DriveMode_Response, error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers i2c_pwm_board_msgs__srv__DriveMode_Response__rosidl_typesupport_introspection_c__DriveMode_Response_message_members = {
  "i2c_pwm_board_msgs__srv",  // message namespace
  "DriveMode_Response",  // message name
  1,  // number of fields
  sizeof(i2c_pwm_board_msgs__srv__DriveMode_Response),
  i2c_pwm_board_msgs__srv__DriveMode_Response__rosidl_typesupport_introspection_c__DriveMode_Response_message_member_array,  // message members
  i2c_pwm_board_msgs__srv__DriveMode_Response__rosidl_typesupport_introspection_c__DriveMode_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  i2c_pwm_board_msgs__srv__DriveMode_Response__rosidl_typesupport_introspection_c__DriveMode_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t i2c_pwm_board_msgs__srv__DriveMode_Response__rosidl_typesupport_introspection_c__DriveMode_Response_message_type_support_handle = {
  0,
  &i2c_pwm_board_msgs__srv__DriveMode_Response__rosidl_typesupport_introspection_c__DriveMode_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_i2c_pwm_board_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i2c_pwm_board_msgs, srv, DriveMode_Response)() {
  if (!i2c_pwm_board_msgs__srv__DriveMode_Response__rosidl_typesupport_introspection_c__DriveMode_Response_message_type_support_handle.typesupport_identifier) {
    i2c_pwm_board_msgs__srv__DriveMode_Response__rosidl_typesupport_introspection_c__DriveMode_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &i2c_pwm_board_msgs__srv__DriveMode_Response__rosidl_typesupport_introspection_c__DriveMode_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "i2c_pwm_board_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "i2c_pwm_board_msgs/srv/detail/drive_mode__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers i2c_pwm_board_msgs__srv__detail__drive_mode__rosidl_typesupport_introspection_c__DriveMode_service_members = {
  "i2c_pwm_board_msgs__srv",  // service namespace
  "DriveMode",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // i2c_pwm_board_msgs__srv__detail__drive_mode__rosidl_typesupport_introspection_c__DriveMode_Request_message_type_support_handle,
  NULL  // response message
  // i2c_pwm_board_msgs__srv__detail__drive_mode__rosidl_typesupport_introspection_c__DriveMode_Response_message_type_support_handle
};

static rosidl_service_type_support_t i2c_pwm_board_msgs__srv__detail__drive_mode__rosidl_typesupport_introspection_c__DriveMode_service_type_support_handle = {
  0,
  &i2c_pwm_board_msgs__srv__detail__drive_mode__rosidl_typesupport_introspection_c__DriveMode_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i2c_pwm_board_msgs, srv, DriveMode_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i2c_pwm_board_msgs, srv, DriveMode_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_i2c_pwm_board_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i2c_pwm_board_msgs, srv, DriveMode)() {
  if (!i2c_pwm_board_msgs__srv__detail__drive_mode__rosidl_typesupport_introspection_c__DriveMode_service_type_support_handle.typesupport_identifier) {
    i2c_pwm_board_msgs__srv__detail__drive_mode__rosidl_typesupport_introspection_c__DriveMode_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)i2c_pwm_board_msgs__srv__detail__drive_mode__rosidl_typesupport_introspection_c__DriveMode_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i2c_pwm_board_msgs, srv, DriveMode_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i2c_pwm_board_msgs, srv, DriveMode_Response)()->data;
  }

  return &i2c_pwm_board_msgs__srv__detail__drive_mode__rosidl_typesupport_introspection_c__DriveMode_service_type_support_handle;
}
