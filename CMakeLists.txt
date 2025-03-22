cmake_minimum_required(VERSION 3.10)

# Project Name
project(ilumin-8)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(ilumin-8 src/main.cpp )

# Include directories
target_include_directories(ilumin-8 PRIVATE include)

# Link libraries
target_link_libraries(ilumin-8 glfw GL)
