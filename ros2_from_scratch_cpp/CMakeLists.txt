cmake_minimum_required(VERSION 3.8)
project(ros2_from_scratch_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

# Include directories
include_directories(include)

# Executables #1
set(SOURCES_1ST_NODE
  src/my_first_node.cpp
  src/main_my_first_node.cpp
)
add_executable(first_node ${SOURCES_1ST_NODE})
ament_target_dependencies(first_node rclcpp)

# Executables #2
add_executable(number_publisher src/number_publisher.cpp)
ament_target_dependencies(number_publisher rclcpp example_interfaces)

# Executables #3
add_executable(number_counter src/number_counter.cpp)
ament_target_dependencies(number_counter rclcpp example_interfaces)


# Installation instructions
install(TARGETS 
  first_node
  DESTINATION lib/${PROJECT_NAME}/
)

# Mark the package
ament_package()
