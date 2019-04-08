cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

project(camera)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(PkgConfig)

pkg_check_modules( OpenCV REQUIRED opencv)
if (OpenCV_FOUND)
    message(STATUS "  OpenCV_LIBS: ${OpenCV_LIBRARIES}")
    message(STATUS "  OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
    message(STATUS "  OpenCV_LIBRARY_DIRS: ${OpenCV_LIBRARY_DIRS}")
    include_directories(${OpenCV_INCLUDE_DIRS})
    link_directories(${OpenCV_LIBRARY_DIRS})
else()
    message(FATAL_ERROR "  opencv Not Found!")
endif()
if (UNIX)
    message(STATUS "under Unix")
else()
    message(STATUS "not under Unix")
endif()

include(FindX11)
if (X11_FOUND)
    include_directories(${X11_INCLUDE_DIR})
    set (dlib_needed_libraries ${dlib_needed_libraries} ${X11_LIBRARIES})
else()
    message(STATUS "X11 not found!")
endif()

add_executable(read-camera src/main.cpp)
target_link_libraries(read-camera ${OpenCV_LIBRARIES})
set_target_properties(read-camera
        PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
)
