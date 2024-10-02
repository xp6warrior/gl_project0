#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 color;
out vec2 texCoord;

uniform vec3 offset;
uniform float scale = 1.0f;

void main() {
    gl_Position = vec4(aPos*scale + offset, 1.0);
    color = aColor;
    texCoord = aTexCoord;
}