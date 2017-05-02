
FIND_LIBRARY(OpenGL_Lib OpenGL)

include_directories(/usr/local/Cellar/sdl2/2.0.5/include/ include)
link_directories(/usr/local/lib/)

file(GLOB sources src/vid_main.cpp)
file(GLOB libsources src/display.cpp)

add_executable(window ${sources})
target_link_libraries(window SDL2 ${OpenGL_Lib})

add_library(libvideo ${libsources})
target_link_libraries(libvideo SDL2 ${OpenGL_Lib})

