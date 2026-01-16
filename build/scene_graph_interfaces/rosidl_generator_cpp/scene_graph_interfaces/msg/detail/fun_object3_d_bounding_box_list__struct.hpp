// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBoxList.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "scene_graph_interfaces/msg/fun_object3_d_bounding_box_list.hpp"


#ifndef SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__STRUCT_HPP_
#define SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'bbox'
#include "scene_graph_interfaces/msg/detail/fun_object3_d_bounding_box__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__scene_graph_interfaces__msg__FunObject3DBoundingBoxList __attribute__((deprecated))
#else
# define DEPRECATED__scene_graph_interfaces__msg__FunObject3DBoundingBoxList __declspec(deprecated)
#endif

namespace scene_graph_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FunObject3DBoundingBoxList_
{
  using Type = FunObject3DBoundingBoxList_<ContainerAllocator>;

  explicit FunObject3DBoundingBoxList_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit FunObject3DBoundingBoxList_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _bbox_type =
    std::vector<scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator>>>;
  _bbox_type bbox;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__bbox(
    const std::vector<scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator>>> & _arg)
  {
    this->bbox = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    scene_graph_interfaces::msg::FunObject3DBoundingBoxList_<ContainerAllocator> *;
  using ConstRawPtr =
    const scene_graph_interfaces::msg::FunObject3DBoundingBoxList_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBoxList_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBoxList_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      scene_graph_interfaces::msg::FunObject3DBoundingBoxList_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBoxList_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      scene_graph_interfaces::msg::FunObject3DBoundingBoxList_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBoxList_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBoxList_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBoxList_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__scene_graph_interfaces__msg__FunObject3DBoundingBoxList
    std::shared_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBoxList_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__scene_graph_interfaces__msg__FunObject3DBoundingBoxList
    std::shared_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBoxList_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FunObject3DBoundingBoxList_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->bbox != other.bbox) {
      return false;
    }
    return true;
  }
  bool operator!=(const FunObject3DBoundingBoxList_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FunObject3DBoundingBoxList_

// alias to use template instance with default allocator
using FunObject3DBoundingBoxList =
  scene_graph_interfaces::msg::FunObject3DBoundingBoxList_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace scene_graph_interfaces

#endif  // SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX_LIST__STRUCT_HPP_
