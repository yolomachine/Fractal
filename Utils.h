//
// Created by metablep on 4/18/18.
//

#pragma once
#include "Settings.h"
#include "Window.h"
#include "Shader.h"

namespace global {
    Window* window;
    Shader* shader;
    GLfloat x_offset = 0.0f;
    GLfloat y_offset = 0.0f;
    GLfloat zoom = 1.0f;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (key == GLFW_KEY_F && action == GLFW_PRESS) {
        global::window->modes.fullscreen = (global::window->modes.fullscreen + 1) % 2;
        glfwSetWindowMonitor(window, global::window->modes.fullscreen ? glfwGetPrimaryMonitor() : nullptr, 48, 48, screen_width - 100.0f, screen_height - 100.0f, GLFW_DONT_CARE);
    }

    if (key >= 0 && key < 1024) {
        if (action == GLFW_PRESS)
            keys[key] = true;
        else if (action == GLFW_RELEASE)
            keys[key] = false;
    }
}

void processMovement() {
    if (keys[GLFW_KEY_LEFT] + keys[GLFW_KEY_A])
        global::x_offset -= 0.01f * global::zoom;
    if (keys[GLFW_KEY_RIGHT] + keys[GLFW_KEY_D])
        global::x_offset += 0.01f * global::zoom;
    if (keys[GLFW_KEY_UP] + keys[GLFW_KEY_W])
        global::y_offset += 0.01f * global::zoom;
    if (keys[GLFW_KEY_DOWN] + keys[GLFW_KEY_S])
        global::y_offset -= 0.01f * global::zoom;
    if (keys[GLFW_KEY_KP_ADD] + keys[GLFW_KEY_LEFT_SHIFT])
        global::zoom /= 1.05f;
    if (keys[GLFW_KEY_KP_SUBTRACT] + keys[GLFW_KEY_LEFT_ALT])
        global::zoom *= 1.05f;
    if (keys[GLFW_KEY_R]) {
        global::x_offset = 0.0f;
        global::y_offset = 0.0f;
        global::zoom = 1.0f;
    }
}
