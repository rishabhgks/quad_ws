# Install script for directory: /home/rishabh/quad_ws/src/quadrotor-tunnel-nav

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/rishabh/quad_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quadrotor_tunnel_nav/msg" TYPE FILE FILES "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/msg/Com.msg")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quadrotor_tunnel_nav/cmake" TYPE FILE FILES "/home/rishabh/quad_ws/build/quadrotor-tunnel-nav/catkin_generated/installspace/quadrotor_tunnel_nav-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/rishabh/quad_ws/devel/include/quadrotor_tunnel_nav")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/rishabh/quad_ws/devel/share/roseus/ros/quadrotor_tunnel_nav")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/rishabh/quad_ws/devel/share/common-lisp/ros/quadrotor_tunnel_nav")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/rishabh/quad_ws/devel/share/gennodejs/ros/quadrotor_tunnel_nav")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/rishabh/quad_ws/devel/lib/python2.7/dist-packages/quadrotor_tunnel_nav")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/rishabh/quad_ws/devel/lib/python2.7/dist-packages/quadrotor_tunnel_nav")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/rishabh/quad_ws/build/quadrotor-tunnel-nav/catkin_generated/installspace/quadrotor_tunnel_nav.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quadrotor_tunnel_nav/cmake" TYPE FILE FILES "/home/rishabh/quad_ws/build/quadrotor-tunnel-nav/catkin_generated/installspace/quadrotor_tunnel_nav-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quadrotor_tunnel_nav/cmake" TYPE FILE FILES
    "/home/rishabh/quad_ws/build/quadrotor-tunnel-nav/catkin_generated/installspace/quadrotor_tunnel_navConfig.cmake"
    "/home/rishabh/quad_ws/build/quadrotor-tunnel-nav/catkin_generated/installspace/quadrotor_tunnel_navConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quadrotor_tunnel_nav" TYPE FILE FILES "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/package.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/rishabh/quad_ws/build/quadrotor-tunnel-nav/catkin_generated/installspace/quadrotor_tunnel_nav.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quadrotor_tunnel_nav/cmake" TYPE FILE FILES
    "/home/rishabh/quad_ws/build/quadrotor-tunnel-nav/catkin_generated/installspace/quadrotor_tunnel_nav-msg-extras.cmake"
    "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/cmake/quadrotor_tunnel_nav-extras.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quadrotor_tunnel_nav/cmake" TYPE FILE FILES
    "/home/rishabh/quad_ws/build/quadrotor-tunnel-nav/catkin_generated/installspace/quadrotor_tunnel_navConfig.cmake"
    "/home/rishabh/quad_ws/build/quadrotor-tunnel-nav/catkin_generated/installspace/quadrotor_tunnel_navConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quadrotor_tunnel_nav" TYPE FILE FILES "/home/rishabh/quad_ws/src/quadrotor-tunnel-nav/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/rishabh/quad_ws/build/quadrotor-tunnel-nav/src/adhoc/protobuf/cmake_install.cmake")

endif()

