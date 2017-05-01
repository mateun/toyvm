cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
project(toyvm)


include_directories(include assembler/include)
file(GLOB sources src/*.cpp)

add_subdirectory(assembler)
add_executable(vmapp ${sources})
target_link_libraries(vmapp libtoyass)
