// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from spider_msgs:msg/SpiderLeg.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_MSGS__MSG__DETAIL__SPIDER_LEG__STRUCT_HPP_
#define SPIDER_MSGS__MSG__DETAIL__SPIDER_LEG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__spider_msgs__msg__SpiderLeg __attribute__((deprecated))
#else
# define DEPRECATED__spider_msgs__msg__SpiderLeg __declspec(deprecated)
#endif

namespace spider_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SpiderLeg_
{
  using Type = SpiderLeg_<ContainerAllocator>;

  explicit SpiderLeg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->hip = 0.0f;
      this->leg = 0.0f;
      this->foot = 0.0f;
      this->smooth_value = 0.0f;
    }
  }

  explicit SpiderLeg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->hip = 0.0f;
      this->leg = 0.0f;
      this->foot = 0.0f;
      this->smooth_value = 0.0f;
    }
  }

  // field types and members
  using _hip_type =
    float;
  _hip_type hip;
  using _leg_type =
    float;
  _leg_type leg;
  using _foot_type =
    float;
  _foot_type foot;
  using _smooth_value_type =
    float;
  _smooth_value_type smooth_value;

  // setters for named parameter idiom
  Type & set__hip(
    const float & _arg)
  {
    this->hip = _arg;
    return *this;
  }
  Type & set__leg(
    const float & _arg)
  {
    this->leg = _arg;
    return *this;
  }
  Type & set__foot(
    const float & _arg)
  {
    this->foot = _arg;
    return *this;
  }
  Type & set__smooth_value(
    const float & _arg)
  {
    this->smooth_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spider_msgs::msg::SpiderLeg_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_msgs::msg::SpiderLeg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_msgs::msg::SpiderLeg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_msgs::msg::SpiderLeg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_msgs::msg::SpiderLeg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::msg::SpiderLeg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_msgs::msg::SpiderLeg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::msg::SpiderLeg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_msgs::msg::SpiderLeg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_msgs::msg::SpiderLeg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_msgs__msg__SpiderLeg
    std::shared_ptr<spider_msgs::msg::SpiderLeg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_msgs__msg__SpiderLeg
    std::shared_ptr<spider_msgs::msg::SpiderLeg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SpiderLeg_ & other) const
  {
    if (this->hip != other.hip) {
      return false;
    }
    if (this->leg != other.leg) {
      return false;
    }
    if (this->foot != other.foot) {
      return false;
    }
    if (this->smooth_value != other.smooth_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const SpiderLeg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SpiderLeg_

// alias to use template instance with default allocator
using SpiderLeg =
  spider_msgs::msg::SpiderLeg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__MSG__DETAIL__SPIDER_LEG__STRUCT_HPP_
