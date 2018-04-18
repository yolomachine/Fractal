//
// Created by metablep on 4/18/18.
//

#pragma once
#include "Settings.h"

class Window {
public:
    struct Modes {
        GLboolean fullscreen;
        GLboolean resizable;
        GLboolean cursorDisabled;
        GLboolean blending;
        GLboolean multisampling;
        GLboolean sepia;

        Modes() : fullscreen(0), resizable(0), cursorDisabled(0), blending(0), multisampling(0), sepia(0) {};
    };

    /**
        @Brief descriprtion of Window() defaults:
        @Fullscreen (windowed);
        @Not resizable window;
        @Enabled cursor;
        @Enabled alpha blending;
        @Antialiasing: 32xMSAA.
      **/
    Window(
            int &&w = 0,
            int &&h = 0,
            const char* title = "Window",
            GLboolean fullscreen     = GL_FALSE,
            GLboolean resizable      = GL_FALSE,
            GLboolean cursorDisabled = GL_FALSE,
            GLboolean blending       = GL_TRUE,
            GLboolean multisampling  = GL_TRUE
    )   : width(w), height(h), title(title) {
        modes.fullscreen        = fullscreen;
        modes.resizable         = resizable;
        modes.cursorDisabled    = cursorDisabled;
        modes.blending          = blending;
        modes.multisampling     = multisampling;
        modes.sepia             = 0;
        glfwWindowPointer       = 0;
    };
    ~Window() = default;

    int init();

    int width;
    int height;
    const char* title;
    Modes modes;

    GLFWwindow* glfwWindowPointer;
};
