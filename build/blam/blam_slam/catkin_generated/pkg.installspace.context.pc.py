# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;rosbag;measurement_synchronizer;point_cloud_filter;point_cloud_odometry;laser_loop_closure;point_cloud_localization;point_cloud_mapper;geometry_utils;parameter_utils;pcl_ros;pcl_conversions".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lblam_slam".split(';') if "-lblam_slam" != "" else []
PROJECT_NAME = "blam_slam"
PROJECT_SPACE_DIR = "/home/rishabh/quad_ws/install"
PROJECT_VERSION = "0.0.0"
