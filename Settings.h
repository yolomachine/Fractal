//
// Created by metablep on 4/18/18.
//

#pragma once

#define GLEW_STATIC
#define OPENGL_MAJOR_VERSION 3
#define OPENGL_MINOR_VERSION 3

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

static bool keys[1024];

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

static const GLfloat screen_width  = 1920.0f;
static const GLfloat screen_height = 1080.0f;

static GLfloat fractalVertices[] = {
    -1.0f,  1.0f,
     1.0f,  1.0f,
    -1.0f, -1.0f,
     1.0f, -1.0f,
};