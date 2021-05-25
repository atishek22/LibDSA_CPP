project(Data_structures_Algorithms)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

find_package(GTest CONFIG REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Both the DS and Algo libraries
add_subdirectory(src)
include_directories(./include)
# Creating the executable
add_executable(Main ./main.cpp)
# linking the libraries
# DSA - Link both the libraries - Recommomended
# Data_structures - Link just the data structures
# Algorithms - Link just the Algorithms
target_link_libraries(Main DSA)

add_subdirectory(./test)
