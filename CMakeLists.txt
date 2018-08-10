cmake_minimum_required(VERSION 2.8)

project(camera)

find_package( OpenCV REQUIRED )

if (NOT OpenCV_FOUND)
    message(FATAL_ERROR "opencv Not Found!")
else()
    message(STATUS "OpenCV_LIBS: ${OpenCV_LIBS}")
    message(STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
endif (NOT OpenCV_FOUND)

# include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(read-camera src/main.cpp)
target_link_libraries(read-camera ${OpenCV_LIBS})
set_target_properties(read-camera
        PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
)