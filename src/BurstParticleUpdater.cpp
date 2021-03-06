//
// Created by Pulkit Juneja on 07/09/18.
//

#include <Engine.h>
#include "BurstParticleUpdater.h"
#include "Globals.h"


void BurstParticleUpdater::update(std::vector<Particle *> &particleContainer) {
    spawnEveryFrame(particleContainer);
    for(std::vector<Particle*>::iterator it = particleContainer.begin();it!=particleContainer.end();) {
        (*it)->velocity +=glm::vec3(0,-4.81,0)*Engine::deltaTime.asSeconds();
        (*it)->position += (*it)->velocity*0.2f;
        (*it)->life -= Engine::deltaTime.asSeconds();
        if((*it)->life<=0) {
            it = particleContainer.erase(it);
        } else {
            ++it;
        }
    }
}

void BurstParticleUpdater::spawnInitial(std::vector<Particle *> &emptyContainer) {
    srand(time(nullptr));
}

void BurstParticleUpdater::spawnEveryFrame(std::vector<Particle *> &particleContainer) {
    spawnTimer += Engine::deltaTime.asSeconds();
    if(spawnTimer >1.0f) {
        spawnTimer = 0 ;
        float posx = -10 + get_random()*10;
        float posy = -10 + get_random()*10;
        for (int i = 0; i < 1000; i++) {
            Particle *p = new Particle();
            p->position = glm::vec3(posx, posy, 0);
			p->size = 0.07f;
            p->color = glm::vec4(get_random(), get_random(), get_random(), 1);
            p->velocity = glm::vec3(-0.5 + get_random() * 1, get_random() * 5, 0);
            p->life = 5;
            particleContainer.push_back(p);
        }
    }
}

float BurstParticleUpdater::get_random() {
    {
        static std::default_random_engine e;
        static std::uniform_real_distribution<> dis(0, 1); // rage 0 - 1
        return dis(e);
    }
}
