//
// Created by metablep on 4/18/18.
//

#pragma once
#include "Settings.h"
#include "Shader.h"

class GLobject {
public:
    GLobject(GLfloat* vertexArray, GLuint size, GLenum usage = GL_STATIC_DRAW)
            : VAO(0), VBO(0), vertexArraySize(size) {
        update(vertexArray, size, usage);
    };
    ~GLobject() {
        unbindVertexArray();
        deleteBuffer();
        deleteVertexArray();
    };

    virtual void draw() = 0;

    void bindVertexArray();
    void unbindVertexArray();


    void deleteVertexArray();
    void deleteBuffer();

    void update(GLfloat* vertexArray, GLuint size, GLenum usage);

    GLuint VAO;
    GLuint VBO;
    GLuint vertexArraySize;
};

class GLfractal : public GLobject {
public:;
    GLfractal(GLfloat* vertexArray, GLuint size, Shader* shader, GLenum usage = GL_STATIC_DRAW) : GLobject(vertexArray, size, usage) {
        shader->setAttribute(VAO, "position", 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
    };

    void draw() override;
};