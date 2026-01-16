cmake_minimum_required(VERSION 3.8)
project(scene_graph_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

# Generate the messages - This creates the .hpp files for your C++ node
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/FunObject3DBoundingBox.msg"
  "msg/FunObject3DBoundingBoxList.msg"
  DEPENDENCIES std_msgs geometry_msgs
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# Export the dependencies so other packages can see them
ament_export_dependencies(rosidl_default_runtime)

ament_package()
