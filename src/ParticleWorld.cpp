#include <ResourceManager.hpp>
#include <ParticleManager.h>
#include "ParticleWorld.h"
#include "SineWaveUpdater.h"
#include "BurstParticleUpdater.h"

bool ParticleWorld::init() {
    ResourceManager::getInstance()->loadShader("Shaders/particle.vert","Shaders/particle.frag","particleShader");
    managers.push_back(new ParticleManager("particleShader", new SineWaveUpdater(0)));
    managers.push_back(new ParticleManager("particleShader", new SineWaveUpdater(10)));
	managers.push_back(new ParticleManager("particleShader", new BurstParticleUpdater()));
    return true;
}

void ParticleWorld::update() {
    for(std::vector<ParticleManager*>::iterator iter = managers.begin();iter!=managers.end();iter++) {
        (*iter)->update();
    }
}

void ParticleWorld::render() {
    for(std::vector<ParticleManager*>::iterator iter = managers.begin();iter!=managers.end();iter++) {
        (*iter)->render();
    }
}


