#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <gl0/gl_project0.hpp>

Renderer renderer;
Camera camera, cam2;
Mesh* meshes[5];

namespace gl0 {

float camX = 0.0f, camY = 0.0f, camZ = 0.0f;
bool camToggle = true;
void getKeyInput(int key, int action) {
    if (action == 2) return;

    switch (key) {
        case 'W':
            camZ += (action == 0) ? -1 : 1; break;
        case 'A': 
            camX += (action == 0) ? 1 : -1; break;
        case 'S':
            camZ += (action == 0) ? 1 : -1; break;
        case 'D':
            camX += (action == 0) ? -1 : 1; break;
        case 32:
            camY += (action == 0) ? -1 : 1; break;
        case 340:
            camY += (action == 0) ? 1 : -1; break;
        case 'Q':
            if (camToggle) {
                renderer.setCamera(cam2);
            } else {
                renderer.setCamera(camera);
            }
            camToggle = !camToggle;
            break;
    };
}

double xCursorOrigin = -1.0;
double yCursorOrigin = -1.0;
float sensitivity = 0.005f;
void getCursorInput(double xpos, double ypos) {
    if (xCursorOrigin == -1.0 && yCursorOrigin == -1.0) {
        xCursorOrigin = xpos;
        yCursorOrigin = ypos;
    }

    if (camToggle) {
        double yaw = (xpos - xCursorOrigin) * sensitivity;
        double pitch = (yCursorOrigin - ypos) * sensitivity;
        camera.rotate(yaw, pitch);
    }
    

    xCursorOrigin = xpos;
    yCursorOrigin = ypos;
}

void Start() {
    //!-- Loading assets --!//
    // Textures
    Texture crate_tex("C:\\Users\\Oliver\\Projects\\OpenGL\\gl_project0\\test\\res\\textures\\container.jpg", 0x1907); // GL_RGB
    Texture face_tex("C:\\Users\\Oliver\\Projects\\OpenGL\\gl_project0\\test\\res\\textures\\awesomeface.png", 0x1908); // GL_RGBA
    Texture disco_tex("C:\\Users\\Oliver\\Projects\\OpenGL\\gl_project0\\test\\res\\textures\\disco_floor.jpg", 0x1907);

    // Shaders
    Shader shader("C:\\Users\\Oliver\\Projects\\OpenGL\\gl_project0\\test\\res\\shaders\\vertex.glsl", "C:\\Users\\Oliver\\Projects\\OpenGL\\gl_project0\\test\\res\\shaders\\fragment.glsl");

    // Materials
    Material floor_mat(shader.getShaderID());
    floor_mat.addTexture(disco_tex.getTextureID(), 0);
    Material cube_mat(shader.getShaderID());
    cube_mat.addTexture(crate_tex.getTextureID(), 0);
    Material skybox_mat(shader.getShaderID());
    skybox_mat.addTexture(face_tex.getTextureID(), 0);

    //!-- Meshs --!//
    Quad* plane = new Quad(floor_mat);
    Cube* c1 = new Cube(cube_mat);
    Cube* c2 = new Cube(cube_mat);
    Cube* c3 = new Cube(cube_mat);
    Cube* skybox = new Cube(skybox_mat);
    meshes[0] = plane;
    meshes[1] = c1;
    meshes[2] = c2;
    meshes[3] = c3;
    meshes[4] = skybox;

    //!-- Rendering --!//
    // Transformations
    plane->translate(0.f, -0.25f, 0.f);
    plane->scale(2.f);
    plane->rotate(90.f, 0.f, 0.f);

    c1->translate(0.0f, 0.12f, 0.0f);
    c1->scale(0.4f);
    c2->translate(0.5f, 0.2f, -0.4f);
    c2->scale(0.25f);
    c3->translate(-0.5f, 0.1f, -0.4f);
    c3->scale(0.2f);
    skybox->scale(10.f);

    // Setup renderer
    camera.setPosition(0.f, 0.f, 1.f);
    camera.setProjectionParams(80.f, 800.f/600.f, 0.1f, 100.f);
    renderer = Renderer(meshes, 5);
    renderer.setCamera(camera);
}

void Update() {
    // Animation steps
    //meshes[0]->rotate(0.f, 0.f, 0.01f);
    meshes[1]->rotate(0.6f, 0.6f, 0.0f);
    meshes[2]->rotate(0.0f, 0.6f, 0.6f);
    meshes[3]->rotate(0.6f, 0.0f, 0.0f);

    glm::vec3 camVector(camX, camY, camZ);
    if (!camVector.x == 0 || !camVector.y == 0 || !camVector.z == 0)
        camVector = glm::normalize(camVector);
    camVector *= 0.01;
    if (camToggle)
        camera.offsetLocal(camVector.x, camVector.y, camVector.z);

    cam2.setPosition((float)(std::sin(glfwGetTime()) * 2.f), 0.8f, (float)(std::cos(glfwGetTime()) * 2.f));
    cam2.setLookPosition(0.f, 0.f, 0.f);

    // Render frame
    renderer.render();
}

void End() {
    for (int i=0; i<5; i++) {
        delete *(meshes+i);
    }
}
};

int main(void) {
    gl0::Init("Learn OpenGL", 800, 600, false);
    return 0;
}