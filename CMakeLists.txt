cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(GLParticles)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/GLTestBed/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/GLTestBed/ext/glm)

add_subdirectory(GLTestBed)

add_executable(GLParticles
        src/main.cpp
        src/ParticleWorld.cpp
        src/ParticleWorld.h
        src/BurstParticleUpdater.cpp
        src/BurstParticleUpdater.h src/SineWaveUpdater.cpp src/SineWaveUpdater.h)

target_link_libraries(GLParticles
        GlTestBed)

# SET(CMAKE_CXX_LINK_FLAGS "-framework OpenGL")