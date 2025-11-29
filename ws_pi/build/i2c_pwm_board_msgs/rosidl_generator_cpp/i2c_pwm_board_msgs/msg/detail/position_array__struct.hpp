// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from i2c_pwm_board_msgs:msg/PositionArray.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__MSG__DETAIL__POSITION_ARRAY__STRUCT_HPP_
#define I2C_PWM_BOARD_MSGS__MSG__DETAIL__POSITION_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'servos'
#include "i2c_pwm_board_msgs/msg/detail/position__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__i2c_pwm_board_msgs__msg__PositionArray __attribute__((deprecated))
#else
# define DEPRECATED__i2c_pwm_board_msgs__msg__PositionArray __declspec(deprecated)
#endif

namespace i2c_pwm_board_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PositionArray_
{
  using Type = PositionArray_<ContainerAllocator>;

  explicit PositionArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit PositionArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _servos_type =
    std::vector<i2c_pwm_board_msgs::msg::Position_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<i2c_pwm_board_msgs::msg::Position_<ContainerAllocator>>>;
  _servos_type servos;

  // setters for named parameter idiom
  Type & set__servos(
    const std::vector<i2c_pwm_board_msgs::msg::Position_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<i2c_pwm_board_msgs::msg::Position_<ContainerAllocator>>> & _arg)
  {
    this->servos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    i2c_pwm_board_msgs::msg::PositionArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const i2c_pwm_board_msgs::msg::PositionArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::msg::PositionArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::msg::PositionArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::msg::PositionArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::msg::PositionArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::msg::PositionArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::msg::PositionArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::msg::PositionArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::msg::PositionArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__i2c_pwm_board_msgs__msg__PositionArray
    std::shared_ptr<i2c_pwm_board_msgs::msg::PositionArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__i2c_pwm_board_msgs__msg__PositionArray
    std::shared_ptr<i2c_pwm_board_msgs::msg::PositionArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PositionArray_ & other) const
  {
    if (this->servos != other.servos) {
      return false;
    }
    return true;
  }
  bool operator!=(const PositionArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PositionArray_

// alias to use template instance with default allocator
using PositionArray =
  i2c_pwm_board_msgs::msg::PositionArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace i2c_pwm_board_msgs

#endif  // I2C_PWM_BOARD_MSGS__MSG__DETAIL__POSITION_ARRAY__STRUCT_HPP_
