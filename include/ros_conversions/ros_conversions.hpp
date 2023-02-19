#ifndef ROS_CONVERSIONS_21
#define ROS_CONVERSIONS_21
#include "conversions/conversions.hpp"
#include "transform/transform.hpp"
#include "meshes/mesh.hpp"
#include <geometry_msgs/TransformStamped.h>
#include "geometry_msgs/Transform.h"
#include "visualization_msgs/Marker.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Quaternion.h"
#include "visualization_msgs/Marker.h"
#include<cstdlib>

namespace ros_conversions {

    
    geometry_msgs::Transform to_ros(geometry::Transform transform);
    geometry_msgs::TransformStamped stamp_and_to_ros(geometry::Transform transform);
    geometry_msgs::Transform to_ros(geometry::Transform transform);


    geometry_msgs::Point to_ros(geometry::Point3D point);
    geometry_msgs::Point to_ros_point(geometry::Transform transform);
    geometry_msgs::Quaternion to_ros_quaternion(float roll, float pitch, float yaw);
    visualization_msgs::Marker to_ros(geometry::VisualMesh mesh);

}
#endif