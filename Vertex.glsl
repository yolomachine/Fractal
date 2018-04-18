#version 330 core

layout(location = 0) in vec2 position;

out vec4 out_position;

void main() {
    gl_Position = out_position = vec4(position, 0.0f, 1.0f);
}
