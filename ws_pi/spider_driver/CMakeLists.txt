cmake_minimum_required(VERSION 3.8)
project(spider_driver)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(spider_msgs REQUIRED)

set(dependencies
  rclcpp
  std_msgs
  spider_msgs
)

include_directories(include)

add_library(${PROJECT_NAME} SHARED
  src/spider_driver/ControllerNode.cpp
)
ament_target_dependencies(${PROJECT_NAME} ${dependencies})
target_link_libraries(${PROJECT_NAME} pigpio pigpiod_if2 pthread)

add_executable(control_main src/controller_node.cpp)
ament_target_dependencies(control_main ${dependencies})
target_link_libraries(control_main
  ${PROJECT_NAME}
  pigpio
  pigpiod_if2
  pthread
)

install(TARGETS
  ${PROJECT_NAME}
  control_main
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY include/
  DESTINATION include/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  find_package(ament_cmake_gtest REQUIRED)
  find_package(ament_index_cpp REQUIRED)
endif()

ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})
ament_export_dependencies(${dependencies})

ament_package()
