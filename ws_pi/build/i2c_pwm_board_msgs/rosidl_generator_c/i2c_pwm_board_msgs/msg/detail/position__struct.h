// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from i2c_pwm_board_msgs:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__MSG__DETAIL__POSITION__STRUCT_H_
#define I2C_PWM_BOARD_MSGS__MSG__DETAIL__POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Position in the package i2c_pwm_board_msgs.
/**
  * the position message is used when configuring drive mode to
  * assign a  servo to a specific wheel positon in the drive system
  * postions are specific toe the desired drive mode
  * ackerman has only one position
  * 1 = drive
  * differential has two positons
  * 1 = left, 2 = right
  * mecanum has four positions
  * 1 = front left, 2 = front right, 3 = rear left, 4 = rear right
  * multiple servos/motors may be used for each positon
 */
typedef struct i2c_pwm_board_msgs__msg__Position
{
  int16_t servo;
  int16_t position;
} i2c_pwm_board_msgs__msg__Position;

// Struct for a sequence of i2c_pwm_board_msgs__msg__Position.
typedef struct i2c_pwm_board_msgs__msg__Position__Sequence
{
  i2c_pwm_board_msgs__msg__Position * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i2c_pwm_board_msgs__msg__Position__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // I2C_PWM_BOARD_MSGS__MSG__DETAIL__POSITION__STRUCT_H_
