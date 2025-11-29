// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from spider_msgs:srv/ServoCalibrate.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_MSGS__SRV__DETAIL__SERVO_CALIBRATE__STRUCT_HPP_
#define SPIDER_MSGS__SRV__DETAIL__SERVO_CALIBRATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__spider_msgs__srv__ServoCalibrate_Request __attribute__((deprecated))
#else
# define DEPRECATED__spider_msgs__srv__ServoCalibrate_Request __declspec(deprecated)
#endif

namespace spider_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ServoCalibrate_Request_
{
  using Type = ServoCalibrate_Request_<ContainerAllocator>;

  explicit ServoCalibrate_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->channel = 0l;
      this->pwm = 0l;
    }
  }

  explicit ServoCalibrate_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->channel = 0l;
      this->pwm = 0l;
    }
  }

  // field types and members
  using _channel_type =
    int32_t;
  _channel_type channel;
  using _pwm_type =
    int32_t;
  _pwm_type pwm;

  // setters for named parameter idiom
  Type & set__channel(
    const int32_t & _arg)
  {
    this->channel = _arg;
    return *this;
  }
  Type & set__pwm(
    const int32_t & _arg)
  {
    this->pwm = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spider_msgs::srv::ServoCalibrate_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_msgs::srv::ServoCalibrate_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_msgs::srv::ServoCalibrate_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_msgs::srv::ServoCalibrate_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::ServoCalibrate_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::ServoCalibrate_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::ServoCalibrate_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::ServoCalibrate_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_msgs::srv::ServoCalibrate_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_msgs::srv::ServoCalibrate_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_msgs__srv__ServoCalibrate_Request
    std::shared_ptr<spider_msgs::srv::ServoCalibrate_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_msgs__srv__ServoCalibrate_Request
    std::shared_ptr<spider_msgs::srv::ServoCalibrate_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ServoCalibrate_Request_ & other) const
  {
    if (this->channel != other.channel) {
      return false;
    }
    if (this->pwm != other.pwm) {
      return false;
    }
    return true;
  }
  bool operator!=(const ServoCalibrate_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ServoCalibrate_Request_

// alias to use template instance with default allocator
using ServoCalibrate_Request =
  spider_msgs::srv::ServoCalibrate_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace spider_msgs


#ifndef _WIN32
# define DEPRECATED__spider_msgs__srv__ServoCalibrate_Response __attribute__((deprecated))
#else
# define DEPRECATED__spider_msgs__srv__ServoCalibrate_Response __declspec(deprecated)
#endif

namespace spider_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ServoCalibrate_Response_
{
  using Type = ServoCalibrate_Response_<ContainerAllocator>;

  explicit ServoCalibrate_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pwm_value = 0l;
      this->status = "";
    }
  }

  explicit ServoCalibrate_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pwm_value = 0l;
      this->status = "";
    }
  }

  // field types and members
  using _pwm_value_type =
    int32_t;
  _pwm_value_type pwm_value;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__pwm_value(
    const int32_t & _arg)
  {
    this->pwm_value = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spider_msgs::srv::ServoCalibrate_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_msgs::srv::ServoCalibrate_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_msgs::srv::ServoCalibrate_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_msgs::srv::ServoCalibrate_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::ServoCalibrate_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::ServoCalibrate_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_msgs::srv::ServoCalibrate_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::srv::ServoCalibrate_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_msgs::srv::ServoCalibrate_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_msgs::srv::ServoCalibrate_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_msgs__srv__ServoCalibrate_Response
    std::shared_ptr<spider_msgs::srv::ServoCalibrate_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_msgs__srv__ServoCalibrate_Response
    std::shared_ptr<spider_msgs::srv::ServoCalibrate_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ServoCalibrate_Response_ & other) const
  {
    if (this->pwm_value != other.pwm_value) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const ServoCalibrate_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ServoCalibrate_Response_

// alias to use template instance with default allocator
using ServoCalibrate_Response =
  spider_msgs::srv::ServoCalibrate_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace spider_msgs

namespace spider_msgs
{

namespace srv
{

struct ServoCalibrate
{
  using Request = spider_msgs::srv::ServoCalibrate_Request;
  using Response = spider_msgs::srv::ServoCalibrate_Response;
};

}  // namespace srv

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__SRV__DETAIL__SERVO_CALIBRATE__STRUCT_HPP_
