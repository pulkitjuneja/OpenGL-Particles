#pragma once
#ifndef Mesh_h
#define Mesh_h

#include <Material.h>
#include "Globals.h"
#include "Shader.h"

class Mesh {
    GLuint VBO,VAO,EBO;
    std::vector<float> vertices;
    std::vector<int> indices;
    Material& mat;
public:
    Mesh (std::vector<float> &vertices, std::vector<int> &indices, const Shader& shader);
    void setupMesh();
    void Draw();
};


#endif /* Mesh_h */
