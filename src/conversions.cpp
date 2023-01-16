#include "ros_conversions/conversions.hpp"

namespace conversions {

    geometry_msgs::Transform to_ros(geometry::Transform transform) {

        geometry_msgs::Transform ros_transform;

        geometry_msgs::Vector3 translation;
        translation.x = transform.get_x();
        translation.y = transform.get_y();
        translation.z = transform.get_z();
        
        
        geometry_msgs::Quaternion q;
        q.x = 0.;
        q.y = 0;
        q.z = 0;
        q.w = 1.0;
        // set x, y, z, w FIX ME!

        ros_transform.translation = translation;
        ros_transform.rotation = q;

        return ros_transform;
    }

    geometry_msgs::TransformStamped stamp_and_to_ros(geometry::Transform transform) {

        geometry_msgs::TransformStamped ros_transform;

        std_msgs::Header header;
        header.frame_id = transform.get_parent().get_name(); // What should this be? The world static frame name?
        using namespace std::chrono;
        header.stamp.sec = duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
        //std::time(0); // The current Unix time.
        
        
        ros_transform.transform = to_ros(transform);
        ros_transform.header = header;
        ros_transform.child_frame_id = transform.get_child().get_name();; // What should this be?

        return ros_transform;
    }
}