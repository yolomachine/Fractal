#version 330 core

uniform vec2 resolution;
uniform vec2 offset;
uniform float zoom;

in vec4 out_position;

layout(location = 0) out vec4 out_color;

vec2 apply_transformations(vec2 v);
float iterations_count(vec2 c);

void main() {
    vec3 color = vec3(0.0f);
    vec2 point = apply_transformations(out_position.xy);
    float n = iterations_count(point);
    color += 0.5f + 0.5f * cos(3.0f + n * 0.15f + vec3(0.0f, 0.6f, 1.0f));
    out_color = vec4(color, 1.0f);
}

vec2 apply_transformations(vec2 v) {
    float ratio = resolution.x / resolution.y;
    return zoom * (v * vec2(ratio, 1.0f)) + offset;
}

float iterations_count(vec2 c) {
    float B = 256.0f;
    float n = 0.0f;
    vec2 z  = vec2(0.0f);

    for( int i = 0; i < 200; i++ ) {
        z = vec2(z.x * z.x - z.y * z.y, 2.0f * z.x * z.y) + c;
        if(dot(z, z) > (B * B))
            break;
        n += 1.0f;
    };

    return n - log2(log2(dot(z,z))) + 4.0f;
}