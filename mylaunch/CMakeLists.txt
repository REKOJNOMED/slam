

cmake_minimum_required(VERSION 2.8.3)
project(mylaunch)

find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)





catkin_package()


include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker ${catkin_EXPORTED_TARGETS})

