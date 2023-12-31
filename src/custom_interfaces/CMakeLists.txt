cmake_minimum_required(VERSION 3.8)
project(custom_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

find_package(std_msgs REQUIRED)

find_package(geometry_msgs REQUIRED)

find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/PersonPose.msg"
  "msg/Tracker.msg"
  "msg/Associations.msg"
  "msg/BoundingBox.msg"
  DEPENDENCIES builtin_interfaces std_msgs
  DEPENDENCIES builtin_interfaces geometry_msgs
)


ament_package()
