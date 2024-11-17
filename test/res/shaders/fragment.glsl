#version 330 core

in vec3 color;
in vec2 texCoord;
in vec3 pos;

out vec4 FragColor;

uniform sampler2D tex0;
uniform sampler2D tex1;

vec3 fernel(float steepness) {
    float dist = sqrt(pow(0.5-texCoord.x, 2) + pow(0.5-texCoord.y, 2));
    float b = (1-steepness*0.5f)/sqrt(0.5f);
    float quad = steepness*pow(dist, 2) + b*dist;
    return vec3(clamp(quad, 0.0f, 1.0f));
}

void main() {
    //FragColor = mix(texture(tex0, texCoord), texture(tex1, texCoord), 0.2);
    //vec3 glow = vec3(0.678f, 0.847f, 0.902f) * fernel(4.0f);
    //FragColor = mix(texture(tex0, texCoord), vec4(glow, 1.0f), 0.4);
    //FragColor = mix(vec4(pos, 1.0f), vec4(glow, 1.0f), 0.4);

    FragColor = texture(tex0, texCoord);
}