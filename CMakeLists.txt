cmake_minimum_required(VERSION 3.0)
project(FiducialMarkerTest01)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV 4.0.0 REQUIRED)
message("OpenCV Version: ${OpenCV_VERSION}")

include_directories(${OpenCV_INCLUDE_DIRS})
message("OpenCV Include dirs: ${OpenCV_INCLUDE_DIRS}")
link_directories(${OpenCV_LIB_DIR})
message("OpenCV LIB DIR: ${OpenCV_LIB_DIR}")

add_executable(basicMarkerDetection basicMarkerDetection.cpp)
target_link_libraries(basicMarkerDetection ${OpenCV_LIBS})

add_executable(markerCreation markerCreation.cpp)
target_link_libraries(markerCreation ${OpenCV_LIBS})

add_executable(poseEstimation poseEstimation.cpp)
target_link_libraries(poseEstimation ${OpenCV_LIBS})