#include <cmath>

#include "objects/renderer.hpp"
#include "objects/shaderProgram.hpp"
#include "objects/shaderParser.hpp"
#include "shapes/triangle.hpp"
#include "shapes/quad.hpp"

Renderer renderer;
ShaderProgram shader;
ShaderProgram shader2;
ShaderProgram colorShader;

void Start() {
    std::string vert_src = shaderParser("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\res\\shaders\\vertex.glsl");
    std::string frag_src = shaderParser("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\res\\shaders\\fragment.glsl");
    std::string frag_src2 = shaderParser("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\res\\shaders\\fragment2.glsl");

    shader.addShader(GL_VERTEX_SHADER, vert_src);
    shader.addShader(GL_FRAGMENT_SHADER, frag_src);
    shader.createProgram();

    shader2.addShader(GL_VERTEX_SHADER, vert_src);
    shader2.addShader(GL_FRAGMENT_SHADER, frag_src);
    shader2.createProgram();

    colorShader.addShader(GL_VERTEX_SHADER, vert_src);
    colorShader.addShader(GL_FRAGMENT_SHADER, frag_src2);
    colorShader.createProgram();

    Quad quad(0.0f, 0.0f, colorShader);
    Triangle tri(0.6f, 0.0f, shader);
    Triangle tri2(-0.6f, 0.0f, shader2);

    renderer.addMesh(quad);
    renderer.addMesh(tri);
    renderer.addMesh(tri2);
}

void Update() {
    float time = glfwGetTime();
    float value = (std::sin(time) / 2.0f) + 0.5f;
    colorShader.updateUniform("color", std::sin(time) / 2.0f + 0.5f, 0.0f, -std::sin(time) / 2.0f + 0.5f);

    renderer.render();
}