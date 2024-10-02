#version 330 core

in vec3 color;
in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D tex0;
uniform sampler2D tex1;
uniform float time = 0.0f;

void main() {
    FragColor = mix(texture(tex0, texCoord) * vec4(color, 1.0f), texture(tex1, texCoord + vec2(0.0f, time/2)), 0.2);
}