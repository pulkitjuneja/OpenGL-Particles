//
// Created by Pulkit Juneja on 15/09/18.
//

#include "SineWaveUpdater.h"
#include <Engine.h>

void SineWaveUpdater::spawnInitial(std::vector<Particle *> &emptyContainer) {
    for(float i = -100; i<=100;i=i+0.25f) {
        Particle *p = new Particle();
        p->position = glm::vec3(i,yPivot,0);
        p->color = glm::vec4((p->position.x/100+1)/2,p->position.y,(p->position.z/10+1)/2,1);
        p->velocity = glm::vec3(0,0,0);
        p->size = 0.3f;
        emptyContainer.push_back(p);
    }
}

void SineWaveUpdater::update(std::vector<Particle *> &particleContainer) {
    yPivot = sin(Engine::timeSinceStart.asSeconds()+displacement)*5;
    for(std::vector<Particle*>::iterator iter = particleContainer.begin();iter!=particleContainer.end();iter++) {
        (*iter)->position.y = yPivot + sin(Engine::timeSinceStart.asSeconds()*(*iter)->position.x/2)*2;
        (*iter)->color = glm::vec4(tan(Engine::timeSinceStart.asSeconds()*(*iter)->position.x)*yPivot,
                                   tan(Engine::timeSinceStart.asSeconds()*(*iter)->position.y),tan(yPivot),1);
    }
}
