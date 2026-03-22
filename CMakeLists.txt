cmake_minimum_required(VERSION 3.10)

# 1. Name your project
project(MyRobotProject)

# 2. Specify the C++ standard (like C++17 or C++20)
set(CMAKE_CXX_STANDARD 17)

# 3. The "Lazy" Way: Tell CMake to find all .cpp files automatically
file(GLOB SOURCES "*.cpp")

# 4. Create the final program using all those found files
add_executable(my_program ${SOURCES})