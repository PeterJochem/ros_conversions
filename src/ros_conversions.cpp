#include "ros_conversions/ros_conversions.hpp"

namespace ros_conversions {

    geometry_msgs::Transform to_ros(geometry::Transform transform) {

        geometry_msgs::Transform ros_transform;

        geometry_msgs::Vector3 translation;
        translation.x = transform.get_x();
        translation.y = transform.get_y();
        translation.z = transform.get_z();
        
        
        geometry_msgs::Quaternion q;
        auto[x, y, z, w] = geometry::conversions::convert_to_quaternion(transform.get_roll(), transform.get_pitch(), transform.get_yaw());
        q.x = x;
        q.y = y;
        q.z = z;
        q.w = w;

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
        ros_transform.child_frame_id = transform.get_child().get_name();

        return ros_transform;
    }

    geometry_msgs::Point to_ros(geometry::Point3D point) {

        geometry_msgs::Point ros_point = geometry_msgs::Point();
        ros_point.x = point.get_x();
        ros_point.y = point.get_y();
        ros_point.z = point.get_z();

        return ros_point;
    }

    geometry_msgs::Quaternion to_ros_quaternion(float roll, float pitch, float yaw) {

        geometry_msgs::Quaternion ros_quaternion = geometry_msgs::Quaternion();
        auto[x, y, z, w] = geometry::conversions::convert_to_quaternion(roll, pitch, yaw);
        ros_quaternion.x = x;
        ros_quaternion.y = y;
        ros_quaternion.z = z;
        ros_quaternion.w = w;

        return ros_quaternion;
    }

    geometry_msgs::Point to_ros_point(geometry::Transform transform) {

        geometry_msgs::Point ros_point = geometry_msgs::Point();
        ros_point.x = transform.get_x();
        ros_point.y = transform.get_y();
        ros_point.z = transform.get_z();

        return ros_point;

    }


    visualization_msgs::Marker to_ros(geometry::VisualMesh mesh) {

        visualization_msgs::Marker mesh_marker = visualization_msgs::Marker();
        
        mesh_marker.id = std::rand(); // Each one needs a random id
        mesh_marker.mesh_resource = "file:///" + mesh.get_file_name();

        mesh_marker.mesh_use_embedded_materials = true;
        mesh_marker.type = mesh_marker.MESH_RESOURCE;
        
        mesh_marker.header.frame_id = mesh.get_transform().get_parent().get_name();

        mesh_marker.scale.x = 1.0;
        mesh_marker.scale.y = 1.0;
        mesh_marker.scale.z = 1.0;

        auto pose = geometry_msgs::Pose();

        geometry::Transform mesh_transform = mesh.get_transform();
        pose.position = to_ros_point(mesh_transform);
        
        pose.orientation = to_ros_quaternion(mesh_transform.get_roll(), mesh_transform.get_pitch(), mesh_transform.get_yaw());

        mesh_marker.pose = pose;

        return mesh_marker;
    }
}