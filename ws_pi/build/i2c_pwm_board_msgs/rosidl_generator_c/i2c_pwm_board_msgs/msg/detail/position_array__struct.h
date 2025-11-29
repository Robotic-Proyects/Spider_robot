// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from i2c_pwm_board_msgs:msg/PositionArray.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__MSG__DETAIL__POSITION_ARRAY__STRUCT_H_
#define I2C_PWM_BOARD_MSGS__MSG__DETAIL__POSITION_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'servos'
#include "i2c_pwm_board_msgs/msg/detail/position__struct.h"

/// Struct defined in msg/PositionArray in the package i2c_pwm_board_msgs.
/**
  * the PositionArray message handles multiple position assignments
  * of servos.
 */
typedef struct i2c_pwm_board_msgs__msg__PositionArray
{
  i2c_pwm_board_msgs__msg__Position__Sequence servos;
} i2c_pwm_board_msgs__msg__PositionArray;

// Struct for a sequence of i2c_pwm_board_msgs__msg__PositionArray.
typedef struct i2c_pwm_board_msgs__msg__PositionArray__Sequence
{
  i2c_pwm_board_msgs__msg__PositionArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i2c_pwm_board_msgs__msg__PositionArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // I2C_PWM_BOARD_MSGS__MSG__DETAIL__POSITION_ARRAY__STRUCT_H_
