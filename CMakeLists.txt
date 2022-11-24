cmake_minimum_required(VERSION 3.0.2)
project(pcd_tools)

set(CMAKE_CXX_STANDARD 14)

find_package(
    PCL REQUIRED
)
find_package(
    libLAS REQUIRED
)

include_directories(${PCL_INCLUDE_DIRS})
include_directories(${libLAS_INCLUDE_DIRS})

link_directories(${PCL_LIBRARY_DIRS})
link_directories(${libLAS_LIBRARY_DIRS})

add_definitions(${PCL_DEFINITIONS})

add_executable(pcdtools src/main.cpp)

target_link_libraries(pcdtools
    ${libLAS_LIBRARIES}
    ${PCL_LIBRARIES}
)