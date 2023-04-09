# cmake_minimum_required(VERSION 3.8)
# project(params_learning)

# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()

# # find dependencies
# find_package(ament_cmake REQUIRED)
# # uncomment the following section in order to fill in
# # further dependencies manually.
# # find_package(<dependency> REQUIRED)

# if(BUILD_TESTING)
#   find_package(ament_lint_auto REQUIRED)
#   # the following line skips the linter which checks for copyrights
#   # uncomment the line when a copyright and license is not present in all source files
#   #set(ament_cmake_copyright_FOUND TRUE)
#   # the following line skips cpplint (only works in a git repo)
#   # uncomment the line when this package is not in a git repo
#   #set(ament_cmake_cpplint_FOUND TRUE)
#   ament_lint_auto_find_test_dependencies()
# endif()

# ament_package()

# cmake_minimum_required(VERSION 3.8)
# project(cam)

# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()

# # find dependencies
# find_package(ament_cmake REQUIRED)
# # uncomment the following section in order to fill in
# # further dependencies manually.
# # find_package(<dependency> REQUIRED)

# if(BUILD_TESTING)
#   find_package(ament_lint_auto REQUIRED)
#   # the following line skips the linter which checks for copyrights
#   # uncomment the line when a copyright and license is not present in all source files
#   #set(ament_cmake_copyright_FOUND TRUE)
#   # the following line skips cpplint (only works in a git repo)
#   # uncomment the line when this package is not in a git repo
#   #set(ament_cmake_cpplint_FOUND TRUE)
#   ament_lint_auto_find_test_dependencies()
# endif()

# ament_package()

cmake_minimum_required(VERSION 3.5)
project(params_learning)

# Find packages and libraries
# find_package(OpenCV 4.5.0 REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rclpy REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
# find_package(cv_bridge REQUIRED)
find_package(sensor_msgs REQUIRED)
# find_package(image_transport REQUIRED)

# Msg Support
find_package(rosidl_default_generators REQUIRED)
# find_package(topic_learning REQUIRED) 

set(dependencies 
  rclcpp
  rclcpp_components
  sensor_msgs
  std_msgs
  # OpenCV

  yaml-cpp
)
# set(MVS_API usr/lib/libgxiapi.so)

# Add include directories
# include_directories(
#   include
#   ${OpenCV_INCLUDE_DIRS}
# )
# include_directories("dependencies/")

# Add executable
add_executable(pub src/pub.cpp)
ament_target_dependencies(pub rclcpp std_msgs)

# Link libraries
# target_link_libraries(pub
#   -lMVSDK
#   ${OpenCV_LIBRARIES}
# )
# target_link_libraries(sub
#   -lMVSDK
#   ${OpenCV_LIBRARIES}
# )
# link_directories(/opt/MvCamCtrlSDK/lib/64/)

# rosidl_generate_interfaces(${PROJECT_NAME}
#   "msg/Test.msg"
# )

# Install executable
install(TARGETS
  pub
  DESTINATION lib/${PROJECT_NAME}
)

# install(TARGETS
#   sub
#   DESTINATION lib/${PROJECT_NAME}
# )

# Install launch files and config files
install(DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME}
)

# Export dependencies
# ament_export_dependencies(
#   rclcpp
#   rclcpp_components
#   cv_bridge
#   sensor_msgs
#   image_transport
# )

# Package export
ament_package()

