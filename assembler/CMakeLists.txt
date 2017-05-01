file(GLOB ass_sources src/*.cpp)

include_directories(../src include)

add_executable(assembler ${ass_sources})
