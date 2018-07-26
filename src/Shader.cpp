#include "Globals.h"
#include "Shader.h"
#include "ResourceManager.hpp"

using namespace std;

Shader::Shader (const string &vertexShaderPath, const string &fragmentShaderPath, string &shaderName) {
    this->shaderName = shaderName;
    unsigned int vertexShader, fragmentShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    
    char* vertexShaderSource;
    readFromFile(vertexShaderPath, vertexShaderSource);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR" << shaderName <<"::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    
    char* fragmentShaderSource;
    readFromFile(fragmentShaderPath, fragmentShaderSource);
    glShaderSource(fragmentShader,1,&fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR" << shaderName <<"::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR"<< shaderName <<"::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::Shader(const GLuint shaderProgram, const string &shaderName) {
    this->shaderProgram = shaderProgram;
    this->shaderName = shaderName;
}

void Shader::readFromFile(const string &fileName, char* & shaderContent) {
    ifstream shaderFile(fileName);
    stringstream buffer;
    buffer << shaderFile.rdbuf();
    shaderContent = new char[buffer.str().length()];
    strcpy(shaderContent, &buffer.str()[0]);
}

void Shader::use() {
    if(!(ResourceManager::getInstance()->currentShader == this)) {
        glUseProgram(shaderProgram);
        ResourceManager::getInstance()->currentShader = this;
    }
}

void Shader::setBool(const string &name, bool value) const {
    glUniform1i (glGetUniformLocation(shaderProgram, name.c_str()), (int)value);
}

void Shader::setInt(const string &name, int value) const {
    glUniform1i (glGetUniformLocation(shaderProgram, name.c_str()), value);
}

void Shader::setFloat(const string &name, float value) const {
    glUniform1f (glGetUniformLocation(shaderProgram, name.c_str()), value);
}
