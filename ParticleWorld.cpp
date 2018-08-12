#include <ResourceManager.hpp>
#include <ParticleManager.h>
#include "ParticleWorld.h"

bool ParticleWorld::init() {

    ResourceManager::getInstance()->loadShader("Shaders/particle.vert","Shaders/particle.frag","particleShader");

    manager = new ParticleManager("particleShader");

    return true;
}

void ParticleWorld::update() {

    manager->update();

}

void ParticleWorld::render() {
    manager->render();
}


