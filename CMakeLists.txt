cmake_minimum_required(VERSION 3.16.3)
project(ros_conversions)

find_package(roscpp)
#long term - find_packaeg(geometry)
# you would install geometry?
# or 
#find_package(Geometry)

include_directories(${roscpp_INCLUDE_DIRS} include ${geometry_INCLUDE_DIRS})
#include_directories(include ../../src/motion_planning_library/src/cpp/geometry/include/)
#include_directories(${geometry_INCLUDE_DIRS})

add_library(ros_conversions
            src/conversions.cpp
)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${EIGEN3_INCLUDE_DIR})

target_link_libraries(ros_conversions PUBLIC ${roscpp_LIBRARIES} geometry)

target_include_directories(ros_conversions PUBLIC /opt/ros/noetic/include ${geometry_INCLUDE_DIRS}) 
#/home/pj/ros_motion_planning/src/motion_planning_library/src/cpp/geometry/include) 
# Allows items linking to this library to find the headers for ROS items.