//
// Created by metablep on 4/18/18.
//

#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>

class Shader {
public:
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    ~Shader() = default;

    void enable();
    void disable();

    void setAttribute(GLuint& VAO, std::string attribName, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid* offset);
    void setUniform1f(const GLchar* name, GLfloat x);
    void setUniform2f(const GLchar* name, GLfloat x, GLfloat y);

    GLuint load(const GLchar* path, GLenum shaderType);

    GLuint program;
};
