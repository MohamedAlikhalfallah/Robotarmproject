// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from scene_graph_interfaces:msg/FunObject3DBoundingBox.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "scene_graph_interfaces/msg/fun_object3_d_bounding_box.hpp"


#ifndef SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX__STRUCT_HPP_
#define SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'name'
#include "std_msgs/msg/detail/string__struct.hpp"
// Member 'bounding_box'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__scene_graph_interfaces__msg__FunObject3DBoundingBox __attribute__((deprecated))
#else
# define DEPRECATED__scene_graph_interfaces__msg__FunObject3DBoundingBox __declspec(deprecated)
#endif

namespace scene_graph_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FunObject3DBoundingBox_
{
  using Type = FunObject3DBoundingBox_<ContainerAllocator>;

  explicit FunObject3DBoundingBox_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->bounding_box.fill(geometry_msgs::msg::Point_<ContainerAllocator>{_init});
      this->graspable = false;
    }
  }

  explicit FunObject3DBoundingBox_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc, _init),
    bounding_box(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->bounding_box.fill(geometry_msgs::msg::Point_<ContainerAllocator>{_alloc, _init});
      this->graspable = false;
    }
  }

  // field types and members
  using _name_type =
    std_msgs::msg::String_<ContainerAllocator>;
  _name_type name;
  using _bounding_box_type =
    std::array<geometry_msgs::msg::Point_<ContainerAllocator>, 2>;
  _bounding_box_type bounding_box;
  using _graspable_type =
    bool;
  _graspable_type graspable;

  // setters for named parameter idiom
  Type & set__name(
    const std_msgs::msg::String_<ContainerAllocator> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__bounding_box(
    const std::array<geometry_msgs::msg::Point_<ContainerAllocator>, 2> & _arg)
  {
    this->bounding_box = _arg;
    return *this;
  }
  Type & set__graspable(
    const bool & _arg)
  {
    this->graspable = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator> *;
  using ConstRawPtr =
    const scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__scene_graph_interfaces__msg__FunObject3DBoundingBox
    std::shared_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__scene_graph_interfaces__msg__FunObject3DBoundingBox
    std::shared_ptr<scene_graph_interfaces::msg::FunObject3DBoundingBox_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FunObject3DBoundingBox_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->bounding_box != other.bounding_box) {
      return false;
    }
    if (this->graspable != other.graspable) {
      return false;
    }
    return true;
  }
  bool operator!=(const FunObject3DBoundingBox_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FunObject3DBoundingBox_

// alias to use template instance with default allocator
using FunObject3DBoundingBox =
  scene_graph_interfaces::msg::FunObject3DBoundingBox_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace scene_graph_interfaces

#endif  // SCENE_GRAPH_INTERFACES__MSG__DETAIL__FUN_OBJECT3_D_BOUNDING_BOX__STRUCT_HPP_
