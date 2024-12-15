cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(my_robot_interfaces REQUIRED)

add_executable(test_node src/my_first_node.cpp)
ament_target_dependencies(test_node rclcpp)

add_executable(number_publisher src/number_publisher.cpp)
ament_target_dependencies(number_publisher rclcpp example_interfaces)

add_executable(number_counter src/number_counter.cpp)
ament_target_dependencies(number_counter rclcpp example_interfaces)

add_executable(my_robot_publisher src/my_robot_publisher.cpp)
ament_target_dependencies(my_robot_publisher rclcpp my_robot_interfaces)

add_executable(my_robot_subscriber src/my_robot_subscriber.cpp)
ament_target_dependencies(my_robot_subscriber rclcpp my_robot_interfaces)

install(TARGETS
 test_node
 number_publisher
 number_counter
 my_robot_publisher
 my_robot_subscriber
 DESTINATION lib/${PROJECT_NAME}/
)

ament_package()