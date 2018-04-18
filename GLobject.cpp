//
// Created by metablep on 4/18/18.
//

#include "GLobject.h"

void GLobject::bindVertexArray() {
    glBindVertexArray(VAO);
}

void GLobject::unbindVertexArray() {
    glBindVertexArray(0);
}

void GLobject::deleteVertexArray() {
    glDeleteVertexArrays(1, &VAO);
}

void GLobject::deleteBuffer() {
    glDeleteBuffers(1, &VBO);
}

void GLobject::update(GLfloat* vertexArray, GLuint size, GLenum usage) {
    if (VAO) {
        unbindVertexArray();
        deleteBuffer();
        deleteVertexArray();
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(vertexArray), vertexArray, usage);
    glBindVertexArray(0);
}

void GLfractal::draw() {
    glDrawArrays(GL_TRIANGLE_STRIP, 0, vertexArraySize);
}