list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
project(problem27)
cmake_minimum_required(VERSION 2.8)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Werror -O3 -Wall -Wextra")
add_executable(problem27 main.cpp)
include_directories(../lib/include)

