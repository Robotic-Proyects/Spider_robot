// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from i2c_pwm_board_msgs:msg/ServoConfig.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG__STRUCT_HPP_
#define I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__i2c_pwm_board_msgs__msg__ServoConfig __attribute__((deprecated))
#else
# define DEPRECATED__i2c_pwm_board_msgs__msg__ServoConfig __declspec(deprecated)
#endif

namespace i2c_pwm_board_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ServoConfig_
{
  using Type = ServoConfig_<ContainerAllocator>;

  explicit ServoConfig_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->servo = 0;
      this->center = 0;
      this->range = 0;
      this->direction = 0;
    }
  }

  explicit ServoConfig_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->servo = 0;
      this->center = 0;
      this->range = 0;
      this->direction = 0;
    }
  }

  // field types and members
  using _servo_type =
    int16_t;
  _servo_type servo;
  using _center_type =
    int16_t;
  _center_type center;
  using _range_type =
    int16_t;
  _range_type range;
  using _direction_type =
    int16_t;
  _direction_type direction;

  // setters for named parameter idiom
  Type & set__servo(
    const int16_t & _arg)
  {
    this->servo = _arg;
    return *this;
  }
  Type & set__center(
    const int16_t & _arg)
  {
    this->center = _arg;
    return *this;
  }
  Type & set__range(
    const int16_t & _arg)
  {
    this->range = _arg;
    return *this;
  }
  Type & set__direction(
    const int16_t & _arg)
  {
    this->direction = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator> *;
  using ConstRawPtr =
    const i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__i2c_pwm_board_msgs__msg__ServoConfig
    std::shared_ptr<i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__i2c_pwm_board_msgs__msg__ServoConfig
    std::shared_ptr<i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ServoConfig_ & other) const
  {
    if (this->servo != other.servo) {
      return false;
    }
    if (this->center != other.center) {
      return false;
    }
    if (this->range != other.range) {
      return false;
    }
    if (this->direction != other.direction) {
      return false;
    }
    return true;
  }
  bool operator!=(const ServoConfig_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ServoConfig_

// alias to use template instance with default allocator
using ServoConfig =
  i2c_pwm_board_msgs::msg::ServoConfig_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace i2c_pwm_board_msgs

#endif  // I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG__STRUCT_HPP_
