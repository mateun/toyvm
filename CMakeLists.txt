cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
set(VERSIONNR 0.0.3)
project(toyvm)

include_directories(include assembler/include video/include)
link_directories(/usr/local/lib/)
file(GLOB sources src/*.cpp)

add_subdirectory(assembler)
add_subdirectory(video)
add_executable(vmapp ${sources})
target_link_libraries(vmapp libtoyass)
target_link_libraries(vmapp libvideo)
