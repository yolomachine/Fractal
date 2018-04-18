//
// Created by metablep on 4/18/18.
//

#include "Shader.h"

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath) {
    GLuint vertex = load(vertexPath, GL_VERTEX_SHADER);
    GLuint fragment = load(fragmentPath, GL_FRAGMENT_SHADER);
    GLint success;
    GLchar infoLog[512];

    program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::enable() {
    glUseProgram(program);
}

void Shader::disable() {
    glUseProgram(0);
}

void Shader::setAttribute(GLuint& VAO, std::string attribName, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid* offset) {
    GLint attribLocation = glGetAttribLocation(program, attribName.c_str());
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(attribLocation);
    glVertexAttribPointer(attribLocation, size, type, normalized, stride, offset);
    glBindVertexArray(0);
}

void Shader::setUniform1f(const GLchar* name, GLfloat x) {
    glUniform1f(glGetUniformLocation(program, name), x);
}

void Shader::setUniform2f(const GLchar* name, GLfloat x, GLfloat y) {
    glUniform2f(glGetUniformLocation(program, name), x, y);
}

GLuint Shader::load(const GLchar* path, GLenum shaderType) {
    std::string code;
    std::ifstream file;
    file.exceptions(std::ifstream::badbit);

    try {
        file.open(path);

        std::stringstream stream;
        stream << file.rdbuf();

        file.close();

        code = stream.str();
    }
    catch (std::ifstream::failure e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }

    const GLchar* shaderCode = code.c_str();
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderCode, NULL);
    glCompileShader(shader);

    GLint success;
    GLchar infoLog[512];

    glGetShaderiv(program, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        fprintf(stderr, "Can't compile shader %s: %s\n", path, infoLog);
    }

    return shader;
}