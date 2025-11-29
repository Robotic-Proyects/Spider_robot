// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from i2c_pwm_board_msgs:msg/ServoConfigArray.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG_ARRAY__STRUCT_H_
#define I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG_ARRAY__STRUCT_H_

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
#include "i2c_pwm_board_msgs/msg/detail/servo_config__struct.h"

/// Struct defined in msg/ServoConfigArray in the package i2c_pwm_board_msgs.
/**
  * the ServoConfigArray message is used to handle multiple assignments
  * of config data to servos. the data is needed to normalize servos to
  * common values to isolate variations from the rest of the user's
  * robot motion code. 
 */
typedef struct i2c_pwm_board_msgs__msg__ServoConfigArray
{
  i2c_pwm_board_msgs__msg__ServoConfig__Sequence servos;
} i2c_pwm_board_msgs__msg__ServoConfigArray;

// Struct for a sequence of i2c_pwm_board_msgs__msg__ServoConfigArray.
typedef struct i2c_pwm_board_msgs__msg__ServoConfigArray__Sequence
{
  i2c_pwm_board_msgs__msg__ServoConfigArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i2c_pwm_board_msgs__msg__ServoConfigArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG_ARRAY__STRUCT_H_
