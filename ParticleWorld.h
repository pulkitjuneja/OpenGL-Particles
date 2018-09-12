#ifndef ParticleWorld_h
#define ParticleWorld_h


#include <Engine.h>
#include <Mesh.h>
#include <ParticleManager.h>

class ParticleWorld : public Engine {

    ParticleManager *manager;
    ParticleUpdater* updater;

public:

    virtual bool init ();
    virtual void update();
    virtual void render();
};

#endif /*ParticleWorld_h*/

