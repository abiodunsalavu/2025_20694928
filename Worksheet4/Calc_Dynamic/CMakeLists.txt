cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(calc_project)

# 1. Change STATIC to SHARED to create a DLL (.dll)
add_library(maths SHARED adder.cpp)

# 2. We remove the STATIC definition block because we are now dynamic
# (Optional) You can define a SHARED macro if your code uses it
add_definitions(-Dmaths_EXPORTS)

# 3. Define the executable (using 'calc' to match your project)
add_executable(calc calc.cpp)

# 4. Link 'calc' to 'maths' 
# This tells the linker to use the generated maths.lib import library
target_link_libraries(calc PRIVATE maths)