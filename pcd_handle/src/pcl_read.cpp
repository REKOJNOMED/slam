#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/io/pcd_io.h>

int main(int argc,char **argv)
{
    ros:init(argc,argv,"pcl_read");
    
    ros:NodeHandle nh;
    ros:Publisher pcl_pub=nh.advertise<sensor_msgs::PointCloud2>("pcl_output",1);
    
    sersor_msgs::Pointcloud2 output;
    pcl::PointCloud<pcl::PointXYZ> cloud;

    pcl::io::loadPCDFile("cloud.pcd",cloud);
   
    pcl::toROSMsg(cloud,output);
    output.header.frame_id="odom";
   
    ros::Rate loop_rate(1);
    
    while(ros::ok())
    {
        pcl_pub.publish(output);
        ros:spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
