#include <cmath>
#include <iostream>

#include "objects/renderer.hpp"
#include "objects/shaderProgram.hpp"
#include "objects/shaderParser.hpp"
#include "objects/texture2D.hpp"
#include "shapes/triangle.hpp"
#include "shapes/quad.hpp"

Renderer renderer;
ShaderProgram shader;

void Start() {
    //!-- Loading assets --!//
    // Shader Source code
    std::string vert_src = shaderParser("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\res\\shaders\\vertex.glsl");
    std::string frag_src = shaderParser("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\res\\shaders\\fragment.glsl");

    // Textures
    Texture2D texture1, texture2;
    texture1.loadTexture("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\src\\container.jpg", GL_RGB);
    texture2.loadTexture("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\src\\awesomeface.png", GL_RGBA);

    //!-- Compile shaders --!//
    shader.addShader(GL_VERTEX_SHADER, vert_src);
    shader.addShader(GL_FRAGMENT_SHADER, frag_src);
    shader.createProgram();


    //!-- Mesh --!//
    // Vertex data
    float verticies[32] = {
        // Verticies            // Colors             // Texture Coords
        -0.3f, -0.3f, 0.0f,     1.0f, 0.0f, 0.0f,     0.0f, 0.0f,
        -0.3f,  0.3f, 0.0f,     0.0f, 1.0f, 0.0f,     0.0f, 1.0f,
         0.3f,  0.3f, 0.0f,     0.0f, 0.0f, 1.0f,     1.0f, 1.0f,
         0.3f, -0.3f, 0.0f,     1.0f, 1.0f, 1.0f,     1.0f, 0.0f
    };
    unsigned int indicies[6] = {
        0, 1, 2,
        2, 3, 0
    };

    // Initialise mesh
    Mesh mesh(verticies, sizeof verticies, indicies, sizeof indicies, shader);

    // Set attributes
    mesh.addAttribute(0, 3, 8, 0);
    mesh.addAttribute(1, 3, 8, 3);
    mesh.addAttribute(2, 2, 8, 6);
    // Set textures
    mesh.addTexture(0, texture1);
    mesh.addTexture(1, texture2);


    //!-- Renderer --!//
    renderer.addMesh(mesh);
}

void Update() {
    // Animation steps
    float time = glfwGetTime();
    float radius = 0.5f;
    shader.updateUniform("offset", std::sin(time)*radius, std::cos(time)*radius, 0.0f);
    shader.updateUniform("scale", std::abs(std::sin(time)) + 0.5f);
    shader.updateUniform("time", time);

    // Render frame
    renderer.render();
}