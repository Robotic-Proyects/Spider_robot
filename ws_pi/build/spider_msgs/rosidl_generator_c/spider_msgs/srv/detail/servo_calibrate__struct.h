// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from spider_msgs:srv/ServoCalibrate.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_MSGS__SRV__DETAIL__SERVO_CALIBRATE__STRUCT_H_
#define SPIDER_MSGS__SRV__DETAIL__SERVO_CALIBRATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ServoCalibrate in the package spider_msgs.
typedef struct spider_msgs__srv__ServoCalibrate_Request
{
  /// Canal del PCA9685
  int32_t channel;
  int32_t pwm;
} spider_msgs__srv__ServoCalibrate_Request;

// Struct for a sequence of spider_msgs__srv__ServoCalibrate_Request.
typedef struct spider_msgs__srv__ServoCalibrate_Request__Sequence
{
  spider_msgs__srv__ServoCalibrate_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_msgs__srv__ServoCalibrate_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ServoCalibrate in the package spider_msgs.
typedef struct spider_msgs__srv__ServoCalibrate_Response
{
  /// PWM generado
  int32_t pwm_value;
  /// Mensaje informativo
  rosidl_runtime_c__String status;
} spider_msgs__srv__ServoCalibrate_Response;

// Struct for a sequence of spider_msgs__srv__ServoCalibrate_Response.
typedef struct spider_msgs__srv__ServoCalibrate_Response__Sequence
{
  spider_msgs__srv__ServoCalibrate_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spider_msgs__srv__ServoCalibrate_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPIDER_MSGS__SRV__DETAIL__SERVO_CALIBRATE__STRUCT_H_
