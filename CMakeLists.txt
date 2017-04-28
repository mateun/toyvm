cmake_minimum_required(VERSION 3.5)
project(toyvm)

file(GLOB sources src/*.cpp)

add_executable(vmapp ${sources})
