# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "enu: 0 messages, 3 services")

set(MSG_I_FLAGS "-Isensor_msgs:/opt/ros/kinetic/share/sensor_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(enu_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/ToENU.srv" NAME_WE)
add_custom_target(_enu_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "enu" "/home/rishabh/quad_ws/src/enu/srv/ToENU.srv" "geometry_msgs/Point:sensor_msgs/NavSatStatus:sensor_msgs/NavSatFix:std_msgs/Header"
)

get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/ToFix.srv" NAME_WE)
add_custom_target(_enu_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "enu" "/home/rishabh/quad_ws/src/enu/srv/ToFix.srv" "geometry_msgs/Point:sensor_msgs/NavSatStatus:sensor_msgs/NavSatFix:std_msgs/Header"
)

get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/FromFix.srv" NAME_WE)
add_custom_target(_enu_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "enu" "/home/rishabh/quad_ws/src/enu/srv/FromFix.srv" "geometry_msgs/Point:sensor_msgs/NavSatStatus:sensor_msgs/NavSatFix:std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(enu
  "/home/rishabh/quad_ws/src/enu/srv/FromFix.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/enu
)
_generate_srv_cpp(enu
  "/home/rishabh/quad_ws/src/enu/srv/ToFix.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/enu
)
_generate_srv_cpp(enu
  "/home/rishabh/quad_ws/src/enu/srv/ToENU.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/enu
)

### Generating Module File
_generate_module_cpp(enu
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/enu
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(enu_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(enu_generate_messages enu_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/ToENU.srv" NAME_WE)
add_dependencies(enu_generate_messages_cpp _enu_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/ToFix.srv" NAME_WE)
add_dependencies(enu_generate_messages_cpp _enu_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/FromFix.srv" NAME_WE)
add_dependencies(enu_generate_messages_cpp _enu_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(enu_gencpp)
add_dependencies(enu_gencpp enu_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS enu_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(enu
  "/home/rishabh/quad_ws/src/enu/srv/FromFix.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/enu
)
_generate_srv_eus(enu
  "/home/rishabh/quad_ws/src/enu/srv/ToFix.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/enu
)
_generate_srv_eus(enu
  "/home/rishabh/quad_ws/src/enu/srv/ToENU.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/enu
)

### Generating Module File
_generate_module_eus(enu
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/enu
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(enu_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(enu_generate_messages enu_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/ToENU.srv" NAME_WE)
add_dependencies(enu_generate_messages_eus _enu_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/ToFix.srv" NAME_WE)
add_dependencies(enu_generate_messages_eus _enu_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/FromFix.srv" NAME_WE)
add_dependencies(enu_generate_messages_eus _enu_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(enu_geneus)
add_dependencies(enu_geneus enu_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS enu_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(enu
  "/home/rishabh/quad_ws/src/enu/srv/FromFix.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/enu
)
_generate_srv_lisp(enu
  "/home/rishabh/quad_ws/src/enu/srv/ToFix.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/enu
)
_generate_srv_lisp(enu
  "/home/rishabh/quad_ws/src/enu/srv/ToENU.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/enu
)

### Generating Module File
_generate_module_lisp(enu
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/enu
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(enu_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(enu_generate_messages enu_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/ToENU.srv" NAME_WE)
add_dependencies(enu_generate_messages_lisp _enu_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/ToFix.srv" NAME_WE)
add_dependencies(enu_generate_messages_lisp _enu_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/FromFix.srv" NAME_WE)
add_dependencies(enu_generate_messages_lisp _enu_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(enu_genlisp)
add_dependencies(enu_genlisp enu_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS enu_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(enu
  "/home/rishabh/quad_ws/src/enu/srv/FromFix.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/enu
)
_generate_srv_nodejs(enu
  "/home/rishabh/quad_ws/src/enu/srv/ToFix.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/enu
)
_generate_srv_nodejs(enu
  "/home/rishabh/quad_ws/src/enu/srv/ToENU.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/enu
)

### Generating Module File
_generate_module_nodejs(enu
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/enu
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(enu_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(enu_generate_messages enu_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/ToENU.srv" NAME_WE)
add_dependencies(enu_generate_messages_nodejs _enu_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/ToFix.srv" NAME_WE)
add_dependencies(enu_generate_messages_nodejs _enu_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/FromFix.srv" NAME_WE)
add_dependencies(enu_generate_messages_nodejs _enu_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(enu_gennodejs)
add_dependencies(enu_gennodejs enu_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS enu_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(enu
  "/home/rishabh/quad_ws/src/enu/srv/FromFix.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/enu
)
_generate_srv_py(enu
  "/home/rishabh/quad_ws/src/enu/srv/ToFix.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/enu
)
_generate_srv_py(enu
  "/home/rishabh/quad_ws/src/enu/srv/ToENU.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/kinetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/enu
)

### Generating Module File
_generate_module_py(enu
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/enu
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(enu_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(enu_generate_messages enu_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/ToENU.srv" NAME_WE)
add_dependencies(enu_generate_messages_py _enu_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/ToFix.srv" NAME_WE)
add_dependencies(enu_generate_messages_py _enu_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rishabh/quad_ws/src/enu/srv/FromFix.srv" NAME_WE)
add_dependencies(enu_generate_messages_py _enu_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(enu_genpy)
add_dependencies(enu_genpy enu_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS enu_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/enu)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/enu
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(enu_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(enu_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/enu)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/enu
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(enu_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(enu_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/enu)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/enu
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(enu_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(enu_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/enu)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/enu
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(enu_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(enu_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/enu)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/enu\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/enu
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(enu_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(enu_generate_messages_py geometry_msgs_generate_messages_py)
endif()
