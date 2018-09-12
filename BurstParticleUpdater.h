//
// Created by Pulkit Juneja on 07/09/18.
//

#ifndef GLPARTICLES_SINEWAVEPARTICLEUPDATER_H
#define GLPARTICLES_SINEWAVEPARTICLEUPDATER_H


#include <ParticleUpdater.h>

class BurstParticleUpdater : public ParticleUpdater {
public:
    void update (std::vector<Particle*> &particleContainer);
    void spawnInitial (std::vector<Particle*> &emptyContainer);
    void spawnEveryFrame (std::vector<Particle *> &particleContainer);
    float get_random();
};


#endif //GLPARTICLES_SINEWAVEPARTICLEUPDATER_H
