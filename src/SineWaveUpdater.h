//
// Created by Pulkit Juneja on 15/09/18.
//

#ifndef GLPARTICLES_SINEWAVEUPDATER_H
#define GLPARTICLES_SINEWAVEUPDATER_H

#include <ParticleUpdater.h>

class SineWaveUpdater : public ParticleUpdater {
    float yPivot;
    float displacement;
public:
    SineWaveUpdater(float displacement) {
        this->displacement = displacement;
    }
    void update (std::vector<Particle*> &particleContainer);
    virtual void spawnInitial (std::vector<Particle*> &emptyContainer);
};

#endif //GLPARTICLES_SINEWAVEUPDATER_H
