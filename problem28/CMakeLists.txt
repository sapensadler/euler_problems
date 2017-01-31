project(problem28)
cmake_minimum_required(VERSION 2.8)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Werror -O3 -Wall -Wextra")
add_executable(problem28 main.cpp)

