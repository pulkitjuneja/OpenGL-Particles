#ifndef ParticleWorld_h
#define ParticleWorld_h


#include <Engine.h>
#include <Mesh.h>
#include <ParticleManager.h>
#include <Camera.h>

class ParticleWorld : public Engine {

    std::vector<ParticleManager* > managers;
	Camera* camera;

public:

    virtual bool init ();
    virtual void update();
    virtual void render();
};

#endif /*ParticleWorld_h*/

