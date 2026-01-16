cmake_minimum_required(VERSION 3.5)
project(piper_bringup)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(moveit_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(control_msgs REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(message_filters REQUIRED)
find_package(scene_graph_interfaces REQUIRED)
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3 REQUIRED)

# Install launch files, rviz configs, worlds
install(DIRECTORY 
  launch 
  rviz 
  worlds 
  DESTINATION share/${PROJECT_NAME}
)

# Install models
install(DIRECTORY
  models
  DESTINATION share/${PROJECT_NAME}
)

# Install Python scripts
install(PROGRAMS
  scripts/pick_and_place.py
  scripts/ik_pick_and_place.py
  scripts/detection_node.py
  DESTINATION lib/${PROJECT_NAME}
)

# C++ executable - Main pick and place with IK debugging
add_executable(moveit_pick_and_place_cpp src/moveit_pick_and_place.cpp)

target_include_directories(moveit_pick_and_place_cpp PUBLIC
  ${EIGEN3_INCLUDE_DIRS}
)

ament_target_dependencies(moveit_pick_and_place_cpp
  rclcpp
  rclcpp_action
  moveit_ros_planning_interface
  moveit_msgs
  geometry_msgs
  control_msgs
  trajectory_msgs
  sensor_msgs
  nav_msgs
  tf2
  tf2_geometry_msgs
  message_filters
  scene_graph_interfaces
)

# Install executables
install(TARGETS
  moveit_pick_and_place_cpp
  DESTINATION lib/${PROJECT_NAME}
)

# Export dependencies
ament_export_dependencies(
  rclcpp
  rclcpp_action
  moveit_ros_planning_interface
  moveit_msgs
  geometry_msgs
  control_msgs
  trajectory_msgs
  sensor_msgs
  nav_msgs
  tf2
  tf2_geometry_msgs
  message_filters
  scene_graph_interfaces
  Eigen3
)

ament_package()