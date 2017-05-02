
FIND_LIBRARY(OpenGL_Lib OpenGL)

include_directories(/usr/local/Cellar/sdl2/2.0.5/include/ include)
link_directories(/usr/local/lib/)

file(GLOB sources src/*.cpp)

add_executable(window ${sources})
target_link_libraries(window SDL2 ${OpenGL_Lib})

