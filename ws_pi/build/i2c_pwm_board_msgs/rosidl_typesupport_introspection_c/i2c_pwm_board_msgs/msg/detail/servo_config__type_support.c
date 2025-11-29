// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from i2c_pwm_board_msgs:msg/ServoConfig.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "i2c_pwm_board_msgs/msg/detail/servo_config__rosidl_typesupport_introspection_c.h"
#include "i2c_pwm_board_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "i2c_pwm_board_msgs/msg/detail/servo_config__functions.h"
#include "i2c_pwm_board_msgs/msg/detail/servo_config__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void i2c_pwm_board_msgs__msg__ServoConfig__rosidl_typesupport_introspection_c__ServoConfig_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  i2c_pwm_board_msgs__msg__ServoConfig__init(message_memory);
}

void i2c_pwm_board_msgs__msg__ServoConfig__rosidl_typesupport_introspection_c__ServoConfig_fini_function(void * message_memory)
{
  i2c_pwm_board_msgs__msg__ServoConfig__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember i2c_pwm_board_msgs__msg__ServoConfig__rosidl_typesupport_introspection_c__ServoConfig_message_member_array[4] = {
  {
    "servo",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i2c_pwm_board_msgs__msg__ServoConfig, servo),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "center",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i2c_pwm_board_msgs__msg__ServoConfig, center),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "range",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i2c_pwm_board_msgs__msg__ServoConfig, range),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "direction",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i2c_pwm_board_msgs__msg__ServoConfig, direction),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers i2c_pwm_board_msgs__msg__ServoConfig__rosidl_typesupport_introspection_c__ServoConfig_message_members = {
  "i2c_pwm_board_msgs__msg",  // message namespace
  "ServoConfig",  // message name
  4,  // number of fields
  sizeof(i2c_pwm_board_msgs__msg__ServoConfig),
  i2c_pwm_board_msgs__msg__ServoConfig__rosidl_typesupport_introspection_c__ServoConfig_message_member_array,  // message members
  i2c_pwm_board_msgs__msg__ServoConfig__rosidl_typesupport_introspection_c__ServoConfig_init_function,  // function to initialize message memory (memory has to be allocated)
  i2c_pwm_board_msgs__msg__ServoConfig__rosidl_typesupport_introspection_c__ServoConfig_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t i2c_pwm_board_msgs__msg__ServoConfig__rosidl_typesupport_introspection_c__ServoConfig_message_type_support_handle = {
  0,
  &i2c_pwm_board_msgs__msg__ServoConfig__rosidl_typesupport_introspection_c__ServoConfig_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_i2c_pwm_board_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i2c_pwm_board_msgs, msg, ServoConfig)() {
  if (!i2c_pwm_board_msgs__msg__ServoConfig__rosidl_typesupport_introspection_c__ServoConfig_message_type_support_handle.typesupport_identifier) {
    i2c_pwm_board_msgs__msg__ServoConfig__rosidl_typesupport_introspection_c__ServoConfig_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &i2c_pwm_board_msgs__msg__ServoConfig__rosidl_typesupport_introspection_c__ServoConfig_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
