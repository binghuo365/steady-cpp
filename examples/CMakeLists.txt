cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)

project (steady_examples)
include_directories(./include)
add_executable(simple simple/main.cpp)

add_dependencies(simple steady)
target_link_libraries(simple steady)

ADD_DEFINITIONS(-DENABLE_DEBUG -DABC)