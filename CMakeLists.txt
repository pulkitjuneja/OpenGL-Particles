cmake_minimum_required(VERSION 3.10)
project(GlTestBed)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_executable(GlTestBed
        src/Globals.h
        src/main.cpp
        src/Mesh.cpp
        src/Mesh.h
        src/ResourceManager.cpp
        src/ResourceManager.hpp
        src/Shader.cpp
        src/Shader.h
        src/stb_image.cpp
        src/stb_image.h src/Material.h src/Engine.cpp src/Engine.h)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

if(APPLE)
include_directories(/usr/local/include)

SET(CMAKE_CXX_LINK_FLAGS "-framework OpenGL")

target_link_libraries(GlTestBed
        /usr/local/Cellar/glew/2.1.0/lib/libGLEW.2.1.0.dylib
        /usr/local/Cellar/sfml/2.4.2_1/lib/libsfml-window.2.4.2.dylib
        /usr/local/Cellar/sfml/2.4.2_1/lib/libsfml-system.2.4.2.dylib)
endif()