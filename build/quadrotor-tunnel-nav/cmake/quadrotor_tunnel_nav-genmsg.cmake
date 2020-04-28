# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "quadrotor_tunnel_nav: 1 messages, 0 services")

set(MSG_I_FLAGS "-Iquadrotor_tunnel_nav:/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(quadrotor_tunnel_nav_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/msg/Com.msg" NAME_WE)
add_custom_target(_quadrotor_tunnel_nav_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "quadrotor_tunnel_nav" "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/msg/Com.msg" "geometry_msgs/Twist:geometry_msgs/Vector3"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(quadrotor_tunnel_nav
  "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/msg/Com.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_tunnel_nav
)

### Generating Services

### Generating Module File
_generate_module_cpp(quadrotor_tunnel_nav
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_tunnel_nav
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(quadrotor_tunnel_nav_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(quadrotor_tunnel_nav_generate_messages quadrotor_tunnel_nav_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/msg/Com.msg" NAME_WE)
add_dependencies(quadrotor_tunnel_nav_generate_messages_cpp _quadrotor_tunnel_nav_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(quadrotor_tunnel_nav_gencpp)
add_dependencies(quadrotor_tunnel_nav_gencpp quadrotor_tunnel_nav_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS quadrotor_tunnel_nav_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(quadrotor_tunnel_nav
  "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/msg/Com.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/quadrotor_tunnel_nav
)

### Generating Services

### Generating Module File
_generate_module_eus(quadrotor_tunnel_nav
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/quadrotor_tunnel_nav
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(quadrotor_tunnel_nav_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(quadrotor_tunnel_nav_generate_messages quadrotor_tunnel_nav_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/msg/Com.msg" NAME_WE)
add_dependencies(quadrotor_tunnel_nav_generate_messages_eus _quadrotor_tunnel_nav_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(quadrotor_tunnel_nav_geneus)
add_dependencies(quadrotor_tunnel_nav_geneus quadrotor_tunnel_nav_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS quadrotor_tunnel_nav_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(quadrotor_tunnel_nav
  "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/msg/Com.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/quadrotor_tunnel_nav
)

### Generating Services

### Generating Module File
_generate_module_lisp(quadrotor_tunnel_nav
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/quadrotor_tunnel_nav
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(quadrotor_tunnel_nav_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(quadrotor_tunnel_nav_generate_messages quadrotor_tunnel_nav_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/msg/Com.msg" NAME_WE)
add_dependencies(quadrotor_tunnel_nav_generate_messages_lisp _quadrotor_tunnel_nav_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(quadrotor_tunnel_nav_genlisp)
add_dependencies(quadrotor_tunnel_nav_genlisp quadrotor_tunnel_nav_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS quadrotor_tunnel_nav_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(quadrotor_tunnel_nav
  "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/msg/Com.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/quadrotor_tunnel_nav
)

### Generating Services

### Generating Module File
_generate_module_nodejs(quadrotor_tunnel_nav
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/quadrotor_tunnel_nav
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(quadrotor_tunnel_nav_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(quadrotor_tunnel_nav_generate_messages quadrotor_tunnel_nav_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/msg/Com.msg" NAME_WE)
add_dependencies(quadrotor_tunnel_nav_generate_messages_nodejs _quadrotor_tunnel_nav_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(quadrotor_tunnel_nav_gennodejs)
add_dependencies(quadrotor_tunnel_nav_gennodejs quadrotor_tunnel_nav_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS quadrotor_tunnel_nav_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(quadrotor_tunnel_nav
  "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/msg/Com.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_tunnel_nav
)

### Generating Services

### Generating Module File
_generate_module_py(quadrotor_tunnel_nav
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_tunnel_nav
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(quadrotor_tunnel_nav_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(quadrotor_tunnel_nav_generate_messages quadrotor_tunnel_nav_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/msg/Com.msg" NAME_WE)
add_dependencies(quadrotor_tunnel_nav_generate_messages_py _quadrotor_tunnel_nav_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(quadrotor_tunnel_nav_genpy)
add_dependencies(quadrotor_tunnel_nav_genpy quadrotor_tunnel_nav_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS quadrotor_tunnel_nav_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_tunnel_nav)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_tunnel_nav
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(quadrotor_tunnel_nav_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(quadrotor_tunnel_nav_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/quadrotor_tunnel_nav)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/quadrotor_tunnel_nav
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(quadrotor_tunnel_nav_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(quadrotor_tunnel_nav_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/quadrotor_tunnel_nav)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/quadrotor_tunnel_nav
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(quadrotor_tunnel_nav_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(quadrotor_tunnel_nav_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/quadrotor_tunnel_nav)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/quadrotor_tunnel_nav
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(quadrotor_tunnel_nav_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(quadrotor_tunnel_nav_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_tunnel_nav)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_tunnel_nav\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_tunnel_nav
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(quadrotor_tunnel_nav_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(quadrotor_tunnel_nav_generate_messages_py geometry_msgs_generate_messages_py)
endif()
