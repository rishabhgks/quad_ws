# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "cmake_modules;geometry_msgs;glog_catkin;mav_msgs;roscpp;sensor_msgs;planning_msgs;tf".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lquad_controller".split(';') if "-lquad_controller" != "" else []
PROJECT_NAME = "quad_control"
PROJECT_SPACE_DIR = "/home/rishabh/quad_ws/install"
PROJECT_VERSION = "0.0.0"