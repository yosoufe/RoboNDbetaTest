cmake_minimum_required(VERSION 3.10)

# set the project name
project(searchBFS)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(searchBFS searchBFS.cpp)

# add the executable
add_executable(astar astar.cpp)

# add the executable
add_executable(realastar realastar.cpp)