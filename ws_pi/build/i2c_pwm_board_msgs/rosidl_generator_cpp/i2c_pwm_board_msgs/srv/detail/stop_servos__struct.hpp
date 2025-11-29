// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from i2c_pwm_board_msgs:srv/StopServos.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__SRV__DETAIL__STOP_SERVOS__STRUCT_HPP_
#define I2C_PWM_BOARD_MSGS__SRV__DETAIL__STOP_SERVOS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__i2c_pwm_board_msgs__srv__StopServos_Request __attribute__((deprecated))
#else
# define DEPRECATED__i2c_pwm_board_msgs__srv__StopServos_Request __declspec(deprecated)
#endif

namespace i2c_pwm_board_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StopServos_Request_
{
  using Type = StopServos_Request_<ContainerAllocator>;

  explicit StopServos_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit StopServos_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    i2c_pwm_board_msgs::srv::StopServos_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const i2c_pwm_board_msgs::srv::StopServos_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::srv::StopServos_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::srv::StopServos_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::srv::StopServos_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::srv::StopServos_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::srv::StopServos_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::srv::StopServos_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::srv::StopServos_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::srv::StopServos_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__i2c_pwm_board_msgs__srv__StopServos_Request
    std::shared_ptr<i2c_pwm_board_msgs::srv::StopServos_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__i2c_pwm_board_msgs__srv__StopServos_Request
    std::shared_ptr<i2c_pwm_board_msgs::srv::StopServos_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StopServos_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const StopServos_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StopServos_Request_

// alias to use template instance with default allocator
using StopServos_Request =
  i2c_pwm_board_msgs::srv::StopServos_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace i2c_pwm_board_msgs


#ifndef _WIN32
# define DEPRECATED__i2c_pwm_board_msgs__srv__StopServos_Response __attribute__((deprecated))
#else
# define DEPRECATED__i2c_pwm_board_msgs__srv__StopServos_Response __declspec(deprecated)
#endif

namespace i2c_pwm_board_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StopServos_Response_
{
  using Type = StopServos_Response_<ContainerAllocator>;

  explicit StopServos_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit StopServos_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    i2c_pwm_board_msgs::srv::StopServos_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const i2c_pwm_board_msgs::srv::StopServos_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::srv::StopServos_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::srv::StopServos_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::srv::StopServos_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::srv::StopServos_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::srv::StopServos_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::srv::StopServos_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::srv::StopServos_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::srv::StopServos_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__i2c_pwm_board_msgs__srv__StopServos_Response
    std::shared_ptr<i2c_pwm_board_msgs::srv::StopServos_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__i2c_pwm_board_msgs__srv__StopServos_Response
    std::shared_ptr<i2c_pwm_board_msgs::srv::StopServos_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StopServos_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const StopServos_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StopServos_Response_

// alias to use template instance with default allocator
using StopServos_Response =
  i2c_pwm_board_msgs::srv::StopServos_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace i2c_pwm_board_msgs

namespace i2c_pwm_board_msgs
{

namespace srv
{

struct StopServos
{
  using Request = i2c_pwm_board_msgs::srv::StopServos_Request;
  using Response = i2c_pwm_board_msgs::srv::StopServos_Response;
};

}  // namespace srv

}  // namespace i2c_pwm_board_msgs

#endif  // I2C_PWM_BOARD_MSGS__SRV__DETAIL__STOP_SERVOS__STRUCT_HPP_
