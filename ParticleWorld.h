#ifndef ParticleWorld_h
#define ParticleWorld_h

#include <Engine.h>
#include <Mesh.h>


class ParticleWorld : public Engine {

    std::vector<float> triangleVertices;
    std::vector<int> triangleIndices;
    Mesh* triangleMesh;

public:

    virtual bool init ();
    virtual void update();
    virtual void render();
};

#endif /*ParticleWorld_h*/
