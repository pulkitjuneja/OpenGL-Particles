//
// Created by Pulkit Juneja on 28/07/18.
//

#ifndef GLTESTBED_MATERIAL_H
#define GLTESTBED_MATERIAL_H

#include <Shader.h>

class Material {

public:
    Shader& shader;
    GLuint& texture;
    Material (Shader& shader, GLuint texture);
};

Material::Material(Shader &shader, GLuint texture): texture(texture), shader(shader) {}

#endif //GLTESTBED_MATERIAL_H
