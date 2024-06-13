#include <iostream>
#include <cmath>

#include "objects/renderer.hpp"
#include "objects/shaderParser.hpp"

float vertices[] = {
     0.5f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f,
     0.5f,  0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f
};
unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
};

float vert2[] = {
    0.25f, 0.25f, 0.0f,
    0.25f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f
};
unsigned int indi2[] = {
    0, 1, 2
};


Renderer renderer;
ShaderProgram shadeProg1;
ShaderProgram shadeProg2;

void Start() {
    std::string vert_src = shaderParser("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\src\\shaders\\vertex.glsl");
    std::string frag_src = shaderParser("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\src\\shaders\\fragment.glsl");
    std::string frag_src2 = shaderParser("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\src\\shaders\\fragment2.glsl");

    shadeProg1.addShader(GL_VERTEX_SHADER, vert_src);
    shadeProg1.addShader(GL_FRAGMENT_SHADER, frag_src);
    shadeProg1.createProgram();

    shadeProg2.addShader(GL_VERTEX_SHADER, vert_src);
    shadeProg2.addShader(GL_FRAGMENT_SHADER, frag_src2);
    shadeProg2.createProgram();

    Mesh quad(vertices, sizeof(vertices), indices, sizeof(indices), shadeProg1);
    Mesh tri(vert2, sizeof(vert2), indi2, sizeof(indi2), shadeProg2);

    renderer.addMesh(quad);
    renderer.addMesh(tri);
}

void Update() {
    float time = glfwGetTime();
    float value = (std::sin(time) / 2.0f) + 0.5f;
    shadeProg1.updateUniform("color", 1.0f, std::sin(time) / 2.0f + 0.5f, 0.0f);
    renderer.render();
}