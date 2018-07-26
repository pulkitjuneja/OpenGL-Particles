#pragma once
#ifndef Mesh_h
#define Mesh_h

#include "Globals.h"
#include "Shader.h"

class Mesh {
    GLuint VBO,VAO,EBO;
    std::vector<float> vertices;
    std::vector<int> indices;
    Shader shader; // remove this hard bounding shader to mesh
public:
    Mesh (std::vector<float> &vertices, std::vector<int> &indices, const Shader& shader);
    Mesh (std::vector<float> &vertices);
    void setupMesh();
    void Draw();
};


#endif /* Mesh_h */
