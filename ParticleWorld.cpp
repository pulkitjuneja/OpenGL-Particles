#include <ResourceManager.hpp>
#include <ParticleManager.h>
#include "ParticleWorld.h"
#include "BurstParticleUpdater.h"

bool ParticleWorld::init() {

    ResourceManager::getInstance()->loadShader("Shaders/particle.vert","Shaders/particle.frag","particleShader");
    updater = new BurstParticleUpdater();
    manager = new ParticleManager("particleShader", *updater);
    return true;
}

void ParticleWorld::update() {
    manager->update();
}

void ParticleWorld::render() {
    manager->render();
}


