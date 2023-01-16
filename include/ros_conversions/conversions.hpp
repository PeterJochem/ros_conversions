#ifndef ROS_CONVERSIONS_1
#define ROS_CONVERSIONS_1
#include "transform/transform.hpp"
#include <geometry_msgs/TransformStamped.h>
#include "geometry_msgs/Transform.h"

namespace conversions {

    //1
    geometry_msgs::Transform to_ros(geometry::Transform transform);
    geometry_msgs::TransformStamped stamp_and_to_ros(geometry::Transform transform);
}
#endif