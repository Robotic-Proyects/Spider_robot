// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from i2c_pwm_board_msgs:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__MSG__DETAIL__POSITION__STRUCT_HPP_
#define I2C_PWM_BOARD_MSGS__MSG__DETAIL__POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__i2c_pwm_board_msgs__msg__Position __attribute__((deprecated))
#else
# define DEPRECATED__i2c_pwm_board_msgs__msg__Position __declspec(deprecated)
#endif

namespace i2c_pwm_board_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Position_
{
  using Type = Position_<ContainerAllocator>;

  explicit Position_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->servo = 0;
      this->position = 0;
    }
  }

  explicit Position_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->servo = 0;
      this->position = 0;
    }
  }

  // field types and members
  using _servo_type =
    int16_t;
  _servo_type servo;
  using _position_type =
    int16_t;
  _position_type position;

  // setters for named parameter idiom
  Type & set__servo(
    const int16_t & _arg)
  {
    this->servo = _arg;
    return *this;
  }
  Type & set__position(
    const int16_t & _arg)
  {
    this->position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    i2c_pwm_board_msgs::msg::Position_<ContainerAllocator> *;
  using ConstRawPtr =
    const i2c_pwm_board_msgs::msg::Position_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::msg::Position_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::msg::Position_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::msg::Position_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::msg::Position_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::msg::Position_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::msg::Position_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::msg::Position_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::msg::Position_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__i2c_pwm_board_msgs__msg__Position
    std::shared_ptr<i2c_pwm_board_msgs::msg::Position_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__i2c_pwm_board_msgs__msg__Position
    std::shared_ptr<i2c_pwm_board_msgs::msg::Position_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Position_ & other) const
  {
    if (this->servo != other.servo) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    return true;
  }
  bool operator!=(const Position_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Position_

// alias to use template instance with default allocator
using Position =
  i2c_pwm_board_msgs::msg::Position_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace i2c_pwm_board_msgs

#endif  // I2C_PWM_BOARD_MSGS__MSG__DETAIL__POSITION__STRUCT_HPP_
