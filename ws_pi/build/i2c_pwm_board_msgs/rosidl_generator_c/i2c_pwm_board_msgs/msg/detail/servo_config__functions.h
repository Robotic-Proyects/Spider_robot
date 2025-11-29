// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from i2c_pwm_board_msgs:msg/ServoConfig.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG__FUNCTIONS_H_
#define I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "i2c_pwm_board_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "i2c_pwm_board_msgs/msg/detail/servo_config__struct.h"

/// Initialize msg/ServoConfig message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * i2c_pwm_board_msgs__msg__ServoConfig
 * )) before or use
 * i2c_pwm_board_msgs__msg__ServoConfig__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs
bool
i2c_pwm_board_msgs__msg__ServoConfig__init(i2c_pwm_board_msgs__msg__ServoConfig * msg);

/// Finalize msg/ServoConfig message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs
void
i2c_pwm_board_msgs__msg__ServoConfig__fini(i2c_pwm_board_msgs__msg__ServoConfig * msg);

/// Create msg/ServoConfig message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * i2c_pwm_board_msgs__msg__ServoConfig__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs
i2c_pwm_board_msgs__msg__ServoConfig *
i2c_pwm_board_msgs__msg__ServoConfig__create();

/// Destroy msg/ServoConfig message.
/**
 * It calls
 * i2c_pwm_board_msgs__msg__ServoConfig__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs
void
i2c_pwm_board_msgs__msg__ServoConfig__destroy(i2c_pwm_board_msgs__msg__ServoConfig * msg);

/// Check for msg/ServoConfig message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs
bool
i2c_pwm_board_msgs__msg__ServoConfig__are_equal(const i2c_pwm_board_msgs__msg__ServoConfig * lhs, const i2c_pwm_board_msgs__msg__ServoConfig * rhs);

/// Copy a msg/ServoConfig message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs
bool
i2c_pwm_board_msgs__msg__ServoConfig__copy(
  const i2c_pwm_board_msgs__msg__ServoConfig * input,
  i2c_pwm_board_msgs__msg__ServoConfig * output);

/// Initialize array of msg/ServoConfig messages.
/**
 * It allocates the memory for the number of elements and calls
 * i2c_pwm_board_msgs__msg__ServoConfig__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs
bool
i2c_pwm_board_msgs__msg__ServoConfig__Sequence__init(i2c_pwm_board_msgs__msg__ServoConfig__Sequence * array, size_t size);

/// Finalize array of msg/ServoConfig messages.
/**
 * It calls
 * i2c_pwm_board_msgs__msg__ServoConfig__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs
void
i2c_pwm_board_msgs__msg__ServoConfig__Sequence__fini(i2c_pwm_board_msgs__msg__ServoConfig__Sequence * array);

/// Create array of msg/ServoConfig messages.
/**
 * It allocates the memory for the array and calls
 * i2c_pwm_board_msgs__msg__ServoConfig__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs
i2c_pwm_board_msgs__msg__ServoConfig__Sequence *
i2c_pwm_board_msgs__msg__ServoConfig__Sequence__create(size_t size);

/// Destroy array of msg/ServoConfig messages.
/**
 * It calls
 * i2c_pwm_board_msgs__msg__ServoConfig__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs
void
i2c_pwm_board_msgs__msg__ServoConfig__Sequence__destroy(i2c_pwm_board_msgs__msg__ServoConfig__Sequence * array);

/// Check for msg/ServoConfig message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs
bool
i2c_pwm_board_msgs__msg__ServoConfig__Sequence__are_equal(const i2c_pwm_board_msgs__msg__ServoConfig__Sequence * lhs, const i2c_pwm_board_msgs__msg__ServoConfig__Sequence * rhs);

/// Copy an array of msg/ServoConfig messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs
bool
i2c_pwm_board_msgs__msg__ServoConfig__Sequence__copy(
  const i2c_pwm_board_msgs__msg__ServoConfig__Sequence * input,
  i2c_pwm_board_msgs__msg__ServoConfig__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG__FUNCTIONS_H_
