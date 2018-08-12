//
// Created by Pulkit Juneja on 08/08/18.
//

#include "ParticleManager.h"
#include "ResourceManager.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <string>

std::vector<GLfloat> billBoardVertexData = std::vector<GLfloat>{
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
        0.5f,  0.5f, 0.0f,
};

// somehow to make this function customizable
void ParticleManager::update() {
    int particleCount = 0;
    for(std::vector<Particle*>::iterator it = particleContainer.begin(); it!=particleContainer.end(); it++){

        particlePositionData.push_back((*it)->position.x);
        particlePositionData.push_back((*it)->position.y);
        particlePositionData.push_back((*it)->position.z);
        particlePositionData.push_back((*it)->position.w);

        particleColorData.push_back((*it)->color.r);
        particleColorData.push_back((*it)->color.g);
        particleColorData.push_back((*it)->color.b);
        particleColorData.push_back((*it)->color.a);

        particleCount++;
    }
}

ParticleManager::ParticleManager(const std::string& shaderName) {
    particleType = ParticleType::billboard;
    particleContainer = std::vector<Particle*>();
    particleContainer.reserve(maxParticles);
    particleShader = ResourceManager::getInstance()->getShader(shaderName);
    particlePositionData.reserve(maxParticles*4);
    particleColorData.reserve(maxParticles*4);
    glGenBuffers(1,&vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER,billBoardVertexData.size()* sizeof(GLfloat), &billBoardVertexData[0], GL_STATIC_DRAW);

    glGenBuffers(1, &vertexPositionBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexPositionBuffer);
    glBufferData(GL_ARRAY_BUFFER,maxParticles* 4 * sizeof(GLfloat),NULL, GL_STATIC_DRAW);

    glGenBuffers(1, &vertexColorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexColorBuffer);
    glBufferData(GL_ARRAY_BUFFER,maxParticles* 4 * sizeof(GLfloat),NULL, GL_STATIC_DRAW);

    spawnInitial();
}

void ParticleManager::render() {

    calculateViewProjectionMatrix();

    particleShader->use();
    particleShader->setFloat3("CameraRight_worldspace", viewMatrix[0][0],viewMatrix[1][0], viewMatrix[2][0]);
    particleShader->setFloat3("CameraUp_worldspace", viewMatrix[0][1], viewMatrix[1][1], viewMatrix[2][1]);

    glm::mat4 viewProjectionMatrix = projectionMatrix * viewMatrix;

    particleShader->setMat4("VP",&viewProjectionMatrix[0][0]);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, vertexPositionBuffer);
    glBufferData(GL_ARRAY_BUFFER,maxParticles*4* sizeof(GLfloat),NULL,GL_STREAM_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER,0,particlePositionData.size()*sizeof(GLfloat),&particlePositionData[0]);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,0,(void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, vertexColorBuffer);
    glBufferData(GL_ARRAY_BUFFER,maxParticles*4* sizeof(GLfloat),NULL,GL_STREAM_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER,0,particleColorData.size()*4*sizeof(GLfloat),&particleColorData[0]);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2,4,GL_FLOAT,GL_FALSE,0,(void*)0);

    glVertexAttribDivisor(0, 0);
    glVertexAttribDivisor(1, 1);
    glVertexAttribDivisor(2, 1);

    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, (GLuint)particleContainer.size());

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
}

void ParticleManager::calculateViewProjectionMatrix() {
    glm::vec3 position( 0, 0, -5 );
    glm::vec3 up(0,1,0);
    glm::vec3 direction(0,0,1); // Initial direction, facing the negative z direction

    viewMatrix = glm::lookAt(position, direction, up);
    projectionMatrix = glm::perspective(glm::radians(45.0f),4.0f/3.0f, 0.1f, 100.0f);

}

void ParticleManager::spawnInitial() {
    for (int i = 0 ; i<100; i ++) {
        Particle* p = new Particle();
        p->position = glm::vec4(rand()%10,rand()%10,rand()%10, 1);
        p->velocity = glm::vec3(0,0,0);
        p->color = glm::vec4(rand()%256, rand()%256, rand()%256,1);
        particleContainer.push_back(p);
    }
}