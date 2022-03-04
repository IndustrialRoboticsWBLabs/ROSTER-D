######## Add this generic test format into the CMakeLists.txt  #############################

if(CATKIN_ENABLE_TESTING)
	# Adding gtest (unit test) Example: http://wiki.ros.org/gtest
	catkin_add_gtest(utest test/utest.cpp) # Example at test/utest.cpp

	# Adding unittest (unit test) Example: http://wiki.ros.org/unittest
	#catkin_add_nosetests(path/to/my_test.py) # No example script for this, follow link for writing my_test.py

	# Adding rostest (used for adding in pytest to CMakeList through the launch file) Example: http://wiki.ros.org/rostest/Writing
	find_package(rostest REQUIRED)
	add_rostest_gtest(${PROJECT_NAME}_utest launch/utest.test test/rosutest.cpp) # gtest
	target_link_libraries(tests_mynode ${catkin_LIBRARIES})

	# Adding rostest (used for adding in pytest to CMakeList through the launch file) Example: http://wiki.ros.org/rostest/Writing
	find_package(rostest REQUIRED) 
	add_rostest(launch/utest.test) # unittest

	# Make sure to add: add_dependencies(),	target_include_directories(), and	target_link_libraries().
	# As well as anything else rquired to start the test nodes.

endif()

######## End Add this into the CMakeLists.txt  ##############################################


####### Example of full CMakeList.txt ###################################################

cmake_minimum_required(VERSION 3.5.0)
project(foo_pkg VERSION 0.1.0 LANGUAGES CXX)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# find_package(yak REQUIRED)
find_package(std_srvs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(cv_bridge REQUIRED)

find_package(Eigen3 REQUIRED)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	pcl_ros
	cv_bridge)

catkin_package(
	INCLUDE_DIRS
		LIBRARIES
			${sensor_msgs_LIBRARIES}
			${cv_bridge_LIBRARIES}
		CATKIN_DEPENDS
			cv_bridge
			geometry_msgs
			pcl_ros
			sensor_msgs
			std_msgs
			visualization_msgs
			)

add_library(${PROJECT_NAME}_visualizer src/generic.cpp)
add_dependencies(${PROJECT_NAME}_visualizer ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_visualizer ${catkin_LIBRARIES})
target_include_directories(${PROJECT_NAME}_visualizer PUBLIC
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<INSTALL_INTERFACE:include>")
target_include_directories(${PROJECT_NAME}_visualizer PUBLIC ${catkin_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}_node
	src/generic.cpp)
target_include_directories(${PROJECT_NAME}_node PUBLIC
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<INSTALL_INTERFACE:include>")
target_include_directories(${PROJECT_NAME}_node PUBLIC
	${catkin_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}_node
	${CATKIN_LIBRARIES}
	${sensor_msgs_LIBRARIES}
	${cv_bridge_LIBRARIES}
	${PROJECT_NAME}_visualizer)

if (CATKIN_ENABLE_TESTING)
 
	catkin_add_gtest(utest test/utest.cpp)

	add_dependencies(utest 
		${catkin_EXPORTED_TARGETS}
		${catkin_DEPENDS}
		${catkin_CATKIN_DEPENDS})

	target_include_directories(utest PUBLIC
		"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
		"$<INSTALL_INTERFACE:include>"
		${catkin_INCLUDE_DIRS}
		${catkin_DEPENDS}
		${catkin_CATKIN_DEPENDS})

	target_link_libraries(utest
		${catkin_LIBRARIES}
		${sensor_msgs_LIBRARIES}
		${cv_bridge_LIBRARIES}
		${PROJECT_NAME}_visualizer)

	find_package(rostest REQUIRED)
	add_rostest_gtest(${PROJECT_NAME}_utest launch/utest.test test/rosutest.cpp)

	add_dependencies(${PROJECT_NAME}_utest 
		${catkin_EXPORTED_TARGETS}
		${catkin_DEPENDS}
		${catkin_CATKIN_DEPENDS})

	target_include_directories(${PROJECT_NAME}_utest PUBLIC
		"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
		"$<INSTALL_INTERFACE:include>"
		${catkin_INCLUDE_DIRS}
		${catkin_DEPENDS}
		${catkin_CATKIN_DEPENDS})

	target_link_libraries(${PROJECT_NAME}_utest
		${catkin_LIBRARIES}
		${sensor_msgs_LIBRARIES}
		${cv_bridge_LIBRARIES}
		${PROJECT_NAME}_visualizer)

endif()
 


install(TARGETS ${PROJECT_NAME}_node ${PROJECT_NAME}_visualizer
	ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
	LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
	RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})



install(DIRECTORY launch demo
	DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

####### End Example of full CMakeList.txt ########################################

