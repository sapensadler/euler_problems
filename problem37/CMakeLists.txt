project(problem37)
cmake_minimum_required(VERSION 2.8)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++14 -Werror -O0 -Wall -Wextra -g")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++14 -Werror -Wall -Wextra -O3")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Werror -Wall -Wextra -O3")
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost COMPONENTS ) 

if(Boost_FOUND)
    add_executable(problem37 main.cpp)
    include_directories(../lib/include ${Boost_INCLUDE_DIRS})
    target_link_libraries(problem37 ${Boost_LIBRARIES})
endif()

