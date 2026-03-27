cmake_minimum_required(VERSION 3.10)

# 1. Name the project
project(SmartHomeProject)

# 2. Specify the C++ standard (like C++17 or C++20)
set(CMAKE_CXX_STANDARD 17)

# 3. Tell CMake to find all .cpp files automatically
file(GLOB SOURCES "*.cpp")

# 4. Create the final program using all the found files
add_executable(smart_home ${SOURCES})