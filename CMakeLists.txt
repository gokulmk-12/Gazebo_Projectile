cmake_minimum_required(VERSION 3.0.2)
project(Gazebo_Projectile)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  gazebo REQUIRED
  gazebo_ros
  gazebo_plugins
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)


include_directories(${GAZEBO_INCLUDE_DIRS})            
link_directories(${GAZEBO_LIBRARY_DIRS})               
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

add_library(gazebo_projectile_plugin SHARED src/projectile_plugin.cc)
target_link_libraries(gazebo_projectile_plugin ${GAZEBO_LIBRARIES})
