cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
project(steady_test)
set(TEST_SRCS unittest.cpp)

add_executable(unittest ${TEST_SRCS})
target_link_libraries(unittest ${CMAKE_THREAD_LIBS_INIT})