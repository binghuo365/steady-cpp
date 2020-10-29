cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
project(steady)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

#find_package(grpc)

MESSAGE(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})
include_directories(./include)
link_directories(./lib)
#include_directories("${PROJECT_INCLUDE_DIR}")
#include_directories("${PROJECT_SOURCE_DIR}")

add_subdirectory(examples)

aux_source_directory(./src SRC_LIST)
add_library(steady STATIC ${SRC_LIST})
#add_executable(simple example/simple/main.cpp)