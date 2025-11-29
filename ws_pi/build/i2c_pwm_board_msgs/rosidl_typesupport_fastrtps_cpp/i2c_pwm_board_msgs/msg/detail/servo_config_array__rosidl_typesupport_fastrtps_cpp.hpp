// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from i2c_pwm_board_msgs:msg/ServoConfigArray.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "i2c_pwm_board_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "i2c_pwm_board_msgs/msg/detail/servo_config_array__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace i2c_pwm_board_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_i2c_pwm_board_msgs
cdr_serialize(
  const i2c_pwm_board_msgs::msg::ServoConfigArray & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_i2c_pwm_board_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  i2c_pwm_board_msgs::msg::ServoConfigArray & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_i2c_pwm_board_msgs
get_serialized_size(
  const i2c_pwm_board_msgs::msg::ServoConfigArray & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_i2c_pwm_board_msgs
max_serialized_size_ServoConfigArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace i2c_pwm_board_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_i2c_pwm_board_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, i2c_pwm_board_msgs, msg, ServoConfigArray)();

#ifdef __cplusplus
}
#endif

#endif  // I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
