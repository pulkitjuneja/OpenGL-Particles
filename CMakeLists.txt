cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(GLParticles)

include_directories(GLTestBed/src)
include_directories(GLTestBed/ext/glm)

add_subdirectory(GLTestBed)

add_executable(GLParticles
        main.cpp
        ParticleWorld.cpp
        ParticleWorld.h
        BurstParticleUpdater.cpp
        BurstParticleUpdater.h)

target_link_libraries(GLParticles
        GlTestBed)

SET(CMAKE_CXX_LINK_FLAGS "-framework OpenGL")
