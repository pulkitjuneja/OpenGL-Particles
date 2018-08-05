#pragma once
#ifndef Shader_h
#define Shader_h

#include "Globals.h"

using namespace std;

class Shader {
    void readFromFile (const string &fileName, char* & shaderContent);
    GLuint shaderProgram;
    string shaderName;
public:
    Shader (const GLuint shaderProgram, const string &shaderName);
    void use();
    void setBool(const string &name, bool value) const;
    void setInt(const string &name, int value) const;
    void setFloat(const string &name, float value) const;
};


#endif /* Shader_h */
