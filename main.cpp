#include "Window.h"
#include "Utils.h"
#include "Shader.h"
#include "GLobject.h"

int main() {
    if (!(global::window = new Window)->init())
        return -1;

    global::shader = new Shader("Vertex.glsl", "Fragment.glsl");
    auto fractal = new GLfractal(fractalVertices, sizeof(fractalVertices) / sizeof(*fractalVertices), global::shader);

    while (!glfwWindowShouldClose(global::window->glfwWindowPointer)) {
        glfwPollEvents();
        processMovement();

        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        global::shader->enable();
        global::shader->setUniform2f("resolution", screen_width, screen_height);
        global::shader->setUniform2f("offset", global::x_offset, global::y_offset);
        global::shader->setUniform1f("zoom", global::zoom);

        fractal->bindVertexArray();
        fractal->draw();
        fractal->unbindVertexArray();
        global::shader->disable();

        glfwSwapInterval(0);
        glfwSwapBuffers(global::window->glfwWindowPointer);
    }

    glfwTerminate();
}