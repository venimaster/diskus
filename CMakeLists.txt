cmake_minimum_required (VERSION 2.8)

project (Diskus)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package (Boost COMPONENTS system filesystem)

# includes
include_directories (${Boost_INCLUDE_DIRS})

add_executable (diskus main.cpp)
target_link_libraries (diskus ${Boost_LIBRARIES})
