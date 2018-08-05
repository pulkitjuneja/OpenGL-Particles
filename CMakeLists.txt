cmake_minimum_required(VERSION 3.10)
project(GLParticles)

set(CMAKE_CXX_STANDARD 11)

add_executable(GLParticles main.cpp ParticleWorld.cpp ParticleWorld.h)

include_directories(GLTestBed/src)
include_directories(GLTestBed/ext)

include_directories(/usr/local/include)

target_link_libraries(GLParticles GlTestBed
        /usr/local/Cellar/glew/2.1.0/lib/libGLEW.2.1.0.dylib
        /usr/local/Cellar/sfml/2.4.2_1/lib/libsfml-window.2.4.2.dylib
        /usr/local/Cellar/sfml/2.4.2_1/lib/libsfml-system.2.4.2.dylib)

SET(CMAKE_CXX_LINK_FLAGS "-framework OpenGL")

add_subdirectory(GLTestBed)


