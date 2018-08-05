#include <ResourceManager.hpp>
#include "ParticleWorld.h"

bool ParticleWorld::init() {

    triangleVertices = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    triangleIndices = {1,2,3};

    triangleMesh = new Mesh(triangleVertices, triangleIndices, new Material(
         ResourceManager::getInstance()->getShader("defaultShader")));

    return true;
}

void ParticleWorld::update() {

}

void ParticleWorld::render() {
    triangleMesh->Draw();
}


