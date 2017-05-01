cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
project(toyvm)


include_directories(include assembler/include)
file(GLOB sources src/*.cpp)

add_executable(vmapp ${sources})
add_subdirectory(assembler)
