// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from spider_msgs:msg/SpiderSwitch.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_MSGS__MSG__DETAIL__SPIDER_SWITCH__STRUCT_HPP_
#define SPIDER_MSGS__MSG__DETAIL__SPIDER_SWITCH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__spider_msgs__msg__SpiderSwitch __attribute__((deprecated))
#else
# define DEPRECATED__spider_msgs__msg__SpiderSwitch __declspec(deprecated)
#endif

namespace spider_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SpiderSwitch_
{
  using Type = SpiderSwitch_<ContainerAllocator>;

  explicit SpiderSwitch_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->oe_value = 0;
    }
  }

  explicit SpiderSwitch_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->oe_value = 0;
    }
  }

  // field types and members
  using _oe_value_type =
    uint8_t;
  _oe_value_type oe_value;

  // setters for named parameter idiom
  Type & set__oe_value(
    const uint8_t & _arg)
  {
    this->oe_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spider_msgs::msg::SpiderSwitch_<ContainerAllocator> *;
  using ConstRawPtr =
    const spider_msgs::msg::SpiderSwitch_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spider_msgs::msg::SpiderSwitch_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spider_msgs::msg::SpiderSwitch_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spider_msgs::msg::SpiderSwitch_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::msg::SpiderSwitch_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spider_msgs::msg::SpiderSwitch_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spider_msgs::msg::SpiderSwitch_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spider_msgs::msg::SpiderSwitch_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spider_msgs::msg::SpiderSwitch_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spider_msgs__msg__SpiderSwitch
    std::shared_ptr<spider_msgs::msg::SpiderSwitch_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spider_msgs__msg__SpiderSwitch
    std::shared_ptr<spider_msgs::msg::SpiderSwitch_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SpiderSwitch_ & other) const
  {
    if (this->oe_value != other.oe_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const SpiderSwitch_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SpiderSwitch_

// alias to use template instance with default allocator
using SpiderSwitch =
  spider_msgs::msg::SpiderSwitch_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__MSG__DETAIL__SPIDER_SWITCH__STRUCT_HPP_
