cmake_minimum_required(VERSION 3.8)
project(demo_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED) #直接查找到头文件和库文件
message(STATUS ${rclcpp_INCLUDE_DIRS}) #头文件以及rclcpp依赖的头文件
message(STATUS ${rclcpp_LIBRARIES})#库文件

add_executable(cpp_node ${PROJECT_SOURCE_DIR}/src/cpp_node.cpp)

#target_link_libraries(cpp_node ${rclcpp_LIBRARIES})
#target_include_directories(cpp_node PUBLIC ${rclcpp_INCLUDE_DIRS})

#这里就是导入了rclcpp依赖
ament_target_dependencies(cpp_node rclcpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
#ros2 pkg create --build-type ament_cmake --license Apache-2.0 demo_cpp_pkg
#通过以上命令创建了功能包，似乎是可以快速创建一个功能包出来