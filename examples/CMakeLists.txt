cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)

project (steady_examples)

add_executable(simple simple/main.cpp)

#target_link_libraries(example_websocket ${Boost_LIBRARIES})