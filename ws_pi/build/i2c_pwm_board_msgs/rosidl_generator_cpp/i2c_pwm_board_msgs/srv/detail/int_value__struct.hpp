// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from i2c_pwm_board_msgs:srv/IntValue.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__SRV__DETAIL__INT_VALUE__STRUCT_HPP_
#define I2C_PWM_BOARD_MSGS__SRV__DETAIL__INT_VALUE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__i2c_pwm_board_msgs__srv__IntValue_Request __attribute__((deprecated))
#else
# define DEPRECATED__i2c_pwm_board_msgs__srv__IntValue_Request __declspec(deprecated)
#endif

namespace i2c_pwm_board_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct IntValue_Request_
{
  using Type = IntValue_Request_<ContainerAllocator>;

  explicit IntValue_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0;
    }
  }

  explicit IntValue_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0;
    }
  }

  // field types and members
  using _value_type =
    int16_t;
  _value_type value;

  // setters for named parameter idiom
  Type & set__value(
    const int16_t & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    i2c_pwm_board_msgs::srv::IntValue_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const i2c_pwm_board_msgs::srv::IntValue_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::srv::IntValue_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::srv::IntValue_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::srv::IntValue_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::srv::IntValue_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::srv::IntValue_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::srv::IntValue_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::srv::IntValue_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::srv::IntValue_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__i2c_pwm_board_msgs__srv__IntValue_Request
    std::shared_ptr<i2c_pwm_board_msgs::srv::IntValue_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__i2c_pwm_board_msgs__srv__IntValue_Request
    std::shared_ptr<i2c_pwm_board_msgs::srv::IntValue_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IntValue_Request_ & other) const
  {
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const IntValue_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IntValue_Request_

// alias to use template instance with default allocator
using IntValue_Request =
  i2c_pwm_board_msgs::srv::IntValue_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace i2c_pwm_board_msgs


#ifndef _WIN32
# define DEPRECATED__i2c_pwm_board_msgs__srv__IntValue_Response __attribute__((deprecated))
#else
# define DEPRECATED__i2c_pwm_board_msgs__srv__IntValue_Response __declspec(deprecated)
#endif

namespace i2c_pwm_board_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct IntValue_Response_
{
  using Type = IntValue_Response_<ContainerAllocator>;

  explicit IntValue_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->error = 0;
    }
  }

  explicit IntValue_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->error = 0;
    }
  }

  // field types and members
  using _error_type =
    int16_t;
  _error_type error;

  // setters for named parameter idiom
  Type & set__error(
    const int16_t & _arg)
  {
    this->error = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    i2c_pwm_board_msgs::srv::IntValue_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const i2c_pwm_board_msgs::srv::IntValue_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::srv::IntValue_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::srv::IntValue_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::srv::IntValue_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::srv::IntValue_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::srv::IntValue_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::srv::IntValue_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::srv::IntValue_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::srv::IntValue_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__i2c_pwm_board_msgs__srv__IntValue_Response
    std::shared_ptr<i2c_pwm_board_msgs::srv::IntValue_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__i2c_pwm_board_msgs__srv__IntValue_Response
    std::shared_ptr<i2c_pwm_board_msgs::srv::IntValue_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IntValue_Response_ & other) const
  {
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const IntValue_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IntValue_Response_

// alias to use template instance with default allocator
using IntValue_Response =
  i2c_pwm_board_msgs::srv::IntValue_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace i2c_pwm_board_msgs

namespace i2c_pwm_board_msgs
{

namespace srv
{

struct IntValue
{
  using Request = i2c_pwm_board_msgs::srv::IntValue_Request;
  using Response = i2c_pwm_board_msgs::srv::IntValue_Response;
};

}  // namespace srv

}  // namespace i2c_pwm_board_msgs

#endif  // I2C_PWM_BOARD_MSGS__SRV__DETAIL__INT_VALUE__STRUCT_HPP_
