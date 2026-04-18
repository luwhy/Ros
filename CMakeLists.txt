cmake_minimum_required(VERSION 3.8)
project(ros2_cpp)

find_package(rclcpp REQUIRED)

add_executable(ros2_cpp_node ${PROJECT_SOURCE_DIR}/src/ros2_cpp_node.cc)

target_link_libraries(ros2_cpp_node ${rclcpp_LIBRARIES})
target_include_directories(ros2_cpp_node PUBLIC ${rclcpp_INCLUDE_DIRS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)