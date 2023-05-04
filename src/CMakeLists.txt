cmake_minimum_required(VERSION 3.13.4)

project(lab2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -m64)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

#project

file(GLOB MY_PROJECT_SRC *.cpp)

add_executable(${PROJECT_NAME} ${MY_PROJECT_SRC}) 

# libs

link_directories(/usr/lib)

