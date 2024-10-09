#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include <cmath>

#include "objects/renderer.hpp"
#include "objects/shaderProgram.hpp"
#include "io/shaderParser.hpp"
#include "objects/texture.hpp"
#include "objects/camera.hpp"
#include "primitives/cube.hpp"
#include "primitives/quad.hpp"

Renderer renderer;
Camera camera;
ShaderProgram planeShader;
Cube* cubes[3];
Quad plane;

glm::mat4 projection(1.0f);
glm::vec3 camOff(0.f, 0.f, 0.f);

void getKeyInput(int key, int action) {
    if (action == 2) return;

    float speed = 0.01f;
    switch (key) {
        case 'W':
            camOff.z += (action == 0) ? speed : -speed; break;
        case 'A': 
            camOff.x += (action == 0) ? speed : -speed; break;
        case 'S':
            camOff.z += (action == 0) ? -speed : speed; break;
        case 'D':
            camOff.x += (action == 0) ? -speed : speed; break;
        case GLFW_KEY_LEFT_SHIFT:
            camOff.y += (action == 0) ? -speed : speed; break;
        case GLFW_KEY_LEFT_CONTROL:
            camOff.y += (action == 0) ? speed : -speed; break;
    };
}

double xCursorOrigin = -1.0;
double yCursorOrigin = -1.0;
float sensitivity = 0.1f;
float yaw = -180.0f;
float pitch = 0.0f;
void getCursorInput(double xpos, double ypos) {
    if (xCursorOrigin == -1.0 && yCursorOrigin == -1.0) {
        xCursorOrigin = xpos;
        yCursorOrigin = ypos;
    }

    yaw -= (xpos - xCursorOrigin) * sensitivity;
    pitch += (yCursorOrigin - ypos) * sensitivity;

    xCursorOrigin = xpos;
    yCursorOrigin = ypos;
}

void Start() {
    //!-- Loading assets --!//
    // Shader Source code
    std::string vert_src = shaderParser("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\res\\shaders\\vertex.glsl");
    std::string frag_src = shaderParser("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\res\\shaders\\fragment.glsl");

    // Textures
    Texture texture1, texture2, texture3;
    texture1.loadTexture("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\res\\textures\\container.jpg", GL_RGB);
    texture2.loadTexture("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\res\\textures\\awesomeface.png", GL_RGBA);
    texture3.loadTexture("C:\\Users\\Oliver\\Desktop\\Programing Portfolio\\Source Code\\OpenGL\\gl_project0\\res\\textures\\disco_floor.jpg", GL_RGB);

    // Compile shaders
    planeShader.addShader(GL_VERTEX_SHADER, vert_src);
    planeShader.addShader(GL_FRAGMENT_SHADER, frag_src);
    planeShader.createProgram();

    //!-- Meshs --!//
    // Plane
    plane = Quad(planeShader);
    plane.addTexture(0, texture3);
    plane.addTexture(1, texture2);

    // Cubes
    for (int i=0; i<3; i++) {
        ShaderProgram shader;
        shader.addShader(GL_VERTEX_SHADER, vert_src);
        shader.addShader(GL_FRAGMENT_SHADER, frag_src);
        shader.createProgram();

        Cube* c = new Cube(shader);
        cubes[i] = c;

        cubes[i]->addTexture(0, texture1);
        cubes[i]->addTexture(1, texture2);
    }


    //!-- Rendering --!//
    // Transformations
    plane.translate(0.f, -0.25f, 0.f);
    plane.scale(2.f);
    plane.rotate(90.f, 0.f, 0.f);

    cubes[0]->translate(0.0f, 0.12f, 0.0f);
    cubes[0]->scale(0.4f);
    cubes[1]->translate(0.5f, 0.2f, -0.4f);
    cubes[1]->scale(0.25f);
    cubes[2]->translate(-0.5f, 0.1f, -0.4f);
    cubes[2]->scale(0.2f);

        //
        projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
        planeShader.updateUniform("projection", glm::value_ptr(projection));

        for (int i=0; i<3; i++) {
            cubes[i]->getShader().updateUniform("projection", glm::value_ptr(projection));
        }
        //

    // Camera
    camera = Camera(glm::vec3(0.f, 0.f, 2.f), glm::vec3(0.f, 0.f, 0.f));
    
    // Setup renderer
    renderer.addCamera(camera);
    renderer.addMesh(plane);
    for (int i=0; i<3; i++) {
        renderer.addMesh(*cubes[i]);
    }
}

void Update() {
    /*/ Animation steps
    cubes[0]->rotate(0.6f, 0.6f, 0.0f);
    cubes[1]->rotate(0.0f, 0.6f, 0.6f);
    cubes[2]->rotate(0.6f, 0.0f, 0.0f);*/

    float time = glfwGetTime() * 1.5f;
    float dim = 0.6f;
    glClearColor(dim*std::sin(time), dim*std::sin(time-(2*M_PI/3)), dim*std::sin(time-(4*M_PI/3)), 1.0f);

    camera.offset(camOff);
    camera.rotate(yaw, pitch);

    // Render frame
    renderer.render();
}

void End() {
    for (int i=0; i<3; i++) {
        delete cubes[i];
    }
}