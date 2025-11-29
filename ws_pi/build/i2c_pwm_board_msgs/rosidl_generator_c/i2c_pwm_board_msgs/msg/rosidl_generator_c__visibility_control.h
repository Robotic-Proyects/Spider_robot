// generated from rosidl_generator_c/resource/rosidl_generator_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
#define I2C_PWM_BOARD_MSGS__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_C_EXPORT_i2c_pwm_board_msgs __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_C_IMPORT_i2c_pwm_board_msgs __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_C_EXPORT_i2c_pwm_board_msgs __declspec(dllexport)
    #define ROSIDL_GENERATOR_C_IMPORT_i2c_pwm_board_msgs __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_C_BUILDING_DLL_i2c_pwm_board_msgs
    #define ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs ROSIDL_GENERATOR_C_EXPORT_i2c_pwm_board_msgs
  #else
    #define ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs ROSIDL_GENERATOR_C_IMPORT_i2c_pwm_board_msgs
  #endif
#else
  #define ROSIDL_GENERATOR_C_EXPORT_i2c_pwm_board_msgs __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_C_IMPORT_i2c_pwm_board_msgs
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_C_PUBLIC_i2c_pwm_board_msgs
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // I2C_PWM_BOARD_MSGS__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
