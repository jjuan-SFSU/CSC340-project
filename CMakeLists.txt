cmake_minimum_required(VERSION 3.21)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(MyProject main.cpp linkedlist.h)
# Add the current directory to the include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Add the executable target
add_executable(MyProject main.cpp linkedlist.cpp)