cmake_minimum_required(VERSION 3.16.3)
project(ros_conversions)
set(CMAKE_CXX_STANDARD 20)

find_package(roscpp)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

#find_package(Geometry)
#include_directories(${geometry_INCLUDE_DIRS}

include_directories(${roscpp_INCLUDE_DIRS} include ${geometry_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIR}) 

add_library(ros_conversions
            src/ros_conversions.cpp
)

target_link_libraries(ros_conversions PUBLIC ${roscpp_LIBRARIES} geometry planning)
target_include_directories(ros_conversions PUBLIC ${roscpp_INCLUDE_DIRS} ${geometry_INCLUDE_DIRS} ${planning_INCLUDE_DIRS})