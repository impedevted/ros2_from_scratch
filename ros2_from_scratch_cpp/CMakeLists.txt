cmake_minimum_required(VERSION 3.8)
project(ros2_from_scratch_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Include directories
include_directories(include)

# Define sources
set(SOURCES
  src/my_first_node.cpp
  src/main_my_first_node.cpp
)

# Create executable
add_executable(first_node ${SOURCES})

# Link dependencies
ament_target_dependencies(first_node rclcpp)

# Installation instructions
install(TARGETS 
  first_node
  DESTINATION lib/${PROJECT_NAME}/
)

# Mark the package
ament_package()
