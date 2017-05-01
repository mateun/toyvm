file(GLOB ass_sources src/main.cpp)
file(GLOB lib_sources src/assembler.cpp)

include_directories(../src include)

add_library(libtoyass ${lib_sources})
add_executable(assembler ${ass_sources})
target_link_libraries(assembler libtoyass)
