#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "objects/renderer.hpp"
#include "objects/shaderProgram.hpp"
#include "io/shaderParser.hpp"
#include "objects/texture2D.hpp"
#include "shapes/triangle.hpp"
#include "shapes/quad.hpp"

Renderer renderer;
ShaderProgram shader;

glm::mat4 local(1.0f);
glm::mat4 view(1.0f);
glm::mat4 projection(1.0f);

void Start() {
    //!-- Loading assets --!//
    // Shader Source code
    std::string vert_src = shaderParser("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\res\\shaders\\vertex.glsl");
    std::string frag_src = shaderParser("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\res\\shaders\\fragment.glsl");

    // Textures
    Texture2D texture1, texture2;
    texture1.loadTexture("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\res\\textures\\container.jpg", GL_RGB);
    texture2.loadTexture("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\res\\textures\\awesomeface.png", GL_RGBA);

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


    //!-- Rendering --!//
    // Transformations
    local = glm::rotate(local, glm::radians(-65.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.updateUniform("local", glm::value_ptr(local));

    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -1.0f));
    shader.updateUniform("view", glm::value_ptr(view));

    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    shader.updateUniform("projection", glm::value_ptr(projection));

    // Add to renderer
    renderer.addMesh(mesh);
}

void Update() {
    // Animation steps
    local = glm::rotate(local, glm::radians(-0.60f), glm::vec3(0.0f, 0.0f, 1.0f));
    shader.updateUniform("local", glm::value_ptr(local));

    // Render frame
    renderer.render();
}