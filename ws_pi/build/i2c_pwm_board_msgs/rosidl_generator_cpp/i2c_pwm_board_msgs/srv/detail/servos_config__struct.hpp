// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from i2c_pwm_board_msgs:srv/ServosConfig.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__SRV__DETAIL__SERVOS_CONFIG__STRUCT_HPP_
#define I2C_PWM_BOARD_MSGS__SRV__DETAIL__SERVOS_CONFIG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'servos'
#include "i2c_pwm_board_msgs/msg/detail/servo_config__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__i2c_pwm_board_msgs__srv__ServosConfig_Request __attribute__((deprecated))
#else
# define DEPRECATED__i2c_pwm_board_msgs__srv__ServosConfig_Request __declspec(deprecated)
#endif

namespace i2c_pwm_board_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ServosConfig_Request_
{
  using Type = ServosConfig_Request_<ContainerAllocator>;

  explicit ServosConfig_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit ServosConfig_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _servos_type =
    std::vector<i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator>>>;
  _servos_type servos;

  // setters for named parameter idiom
  Type & set__servos(
    const std::vector<i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<i2c_pwm_board_msgs::msg::ServoConfig_<ContainerAllocator>>> & _arg)
  {
    this->servos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    i2c_pwm_board_msgs::srv::ServosConfig_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const i2c_pwm_board_msgs::srv::ServosConfig_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::srv::ServosConfig_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::srv::ServosConfig_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__i2c_pwm_board_msgs__srv__ServosConfig_Request
    std::shared_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__i2c_pwm_board_msgs__srv__ServosConfig_Request
    std::shared_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ServosConfig_Request_ & other) const
  {
    if (this->servos != other.servos) {
      return false;
    }
    return true;
  }
  bool operator!=(const ServosConfig_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ServosConfig_Request_

// alias to use template instance with default allocator
using ServosConfig_Request =
  i2c_pwm_board_msgs::srv::ServosConfig_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace i2c_pwm_board_msgs


#ifndef _WIN32
# define DEPRECATED__i2c_pwm_board_msgs__srv__ServosConfig_Response __attribute__((deprecated))
#else
# define DEPRECATED__i2c_pwm_board_msgs__srv__ServosConfig_Response __declspec(deprecated)
#endif

namespace i2c_pwm_board_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ServosConfig_Response_
{
  using Type = ServosConfig_Response_<ContainerAllocator>;

  explicit ServosConfig_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->error = 0;
    }
  }

  explicit ServosConfig_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    i2c_pwm_board_msgs::srv::ServosConfig_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const i2c_pwm_board_msgs::srv::ServosConfig_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::srv::ServosConfig_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      i2c_pwm_board_msgs::srv::ServosConfig_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__i2c_pwm_board_msgs__srv__ServosConfig_Response
    std::shared_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__i2c_pwm_board_msgs__srv__ServosConfig_Response
    std::shared_ptr<i2c_pwm_board_msgs::srv::ServosConfig_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ServosConfig_Response_ & other) const
  {
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const ServosConfig_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ServosConfig_Response_

// alias to use template instance with default allocator
using ServosConfig_Response =
  i2c_pwm_board_msgs::srv::ServosConfig_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace i2c_pwm_board_msgs

namespace i2c_pwm_board_msgs
{

namespace srv
{

struct ServosConfig
{
  using Request = i2c_pwm_board_msgs::srv::ServosConfig_Request;
  using Response = i2c_pwm_board_msgs::srv::ServosConfig_Response;
};

}  // namespace srv

}  // namespace i2c_pwm_board_msgs

#endif  // I2C_PWM_BOARD_MSGS__SRV__DETAIL__SERVOS_CONFIG__STRUCT_HPP_
