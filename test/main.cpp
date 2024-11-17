#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

#include <gl_project0.hpp>
#include <Objects/shaderParser.hpp>

Renderer renderer;
Camera camera;
Mesh meshes[4];

namespace gl0 {

float camX = 0.0f, camY = 0.0f, camZ = 0.0f;
void getKeyInput(int key, int action) {
    if (action == 2) return;

    float speed = 0.01f;
    switch (key) {
        case 'W':
            camZ += (action == 0) ? -speed : speed; break;
        case 'A': 
            camX += (action == 0) ? speed : -speed; break;
        case 'S':
            camZ += (action == 0) ? speed : -speed; break;
        case 'D':
            camX += (action == 0) ? -speed : speed; break;
        case 32: //SPACE
            camY += (action == 0) ? -speed : speed; break;
        case 340: //LEFT_SHIFT
            camY += (action == 0) ? speed : -speed; break;
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

    float yaw = (xpos - xCursorOrigin) * sensitivity;
    float pitch = (yCursorOrigin - ypos) * sensitivity;
    camera.rotate(yaw, pitch);

    xCursorOrigin = xpos;
    yCursorOrigin = ypos;
}

void Start() {
    //!-- Loading assets --!//
    // Shader Source code
    std::string vert_src = shaderParser("C:\\Users\\Oliver\\Projects\\Source Code\\OpenGL\\gl_project0\\test\\res\\shaders\\vertex.glsl");
    std::string frag_src = shaderParser("C:\\Users\\Oliver\\Projects\\Source Code\\OpenGL\\gl_project0\\test\\res\\shaders\\fragment.glsl");

    // Textures
    Texture texture1, texture2, texture3;
    texture1.loadTexture("C:\\Users\\Oliver\\Projects\\Source Code\\OpenGL\\gl_project0\\test\\res\\textures\\container.jpg", 0x1907); // GL_RGB
    texture2.loadTexture("C:\\Users\\Oliver\\Projects\\Source Code\\OpenGL\\gl_project0\\test\\res\\textures\\awesomeface.png", 0x1908); // GL_RGBA
    texture3.loadTexture("C:\\Users\\Oliver\\Projects\\Source Code\\OpenGL\\gl_project0\\test\\res\\textures\\disco_floor.jpg", 0x1907);

    // Compile shaders
    ShaderProgram planeShader;
    planeShader.addShader(0x8B31, vert_src); // GL_VERTEX_SHADER
    planeShader.addShader(0x8B30, frag_src); // GL_FRAGMENT_SHADER
    planeShader.createProgram();

    ShaderProgram cubeShader;
    cubeShader.addShader(0x8B31, vert_src);
    cubeShader.addShader(0x8B30, frag_src);
    cubeShader.createProgram();
    ShaderProgram cubeShader2;
    cubeShader2.addShader(0x8B31, vert_src);
    cubeShader2.addShader(0x8B30, frag_src);
    cubeShader2.createProgram();
    ShaderProgram cubeShader3;
    cubeShader3.addShader(0x8B31, vert_src);
    cubeShader3.addShader(0x8B30, frag_src);
    cubeShader3.createProgram();

    //!-- Meshs --!//
    // Plane
    Quad plane(planeShader);
    plane.addTexture(0, texture3);
    plane.addTexture(1, texture2);
    meshes[0] = plane;

    // Cubes
    Cube c1(cubeShader), c2(cubeShader2), c3(cubeShader3);
    c1.addTexture(0, texture1);
    c1.addTexture(1, texture2);
    c2.addTexture(0, texture1);
    c2.addTexture(1, texture2);
    c3.addTexture(0, texture1);
    c3.addTexture(1, texture2);


    //!-- Rendering --!//
    // Transformations
    plane.translate(0.f, -0.25f, 0.f);
    plane.scale(2.f);
    plane.rotate(90.f, 0.f, 0.f);

    c1.translate(0.0f, 0.12f, 0.0f);
    c1.scale(0.4f);
    c2.translate(0.5f, 0.2f, -0.4f);
    c2.scale(0.25f);
    c3.translate(-0.5f, 0.1f, -0.4f);
    c3.scale(0.2f);

    meshes[1] = c1;
    meshes[2] = c2;
    meshes[3] = c3;

    camera.setPosition(0.f, 1.f, 0.f);
    camera.setLookPosition(0.f, 0.f, 0.f); // not doing max pitch thing

    // Setup renderer
    renderer = Renderer((Mesh*)meshes, 4);
    renderer.addCamera(camera);
}

void Update() {
    // Animation steps
    //((Cube*)meshes[0])->rotate(0.6f, 0.6f, 0.0f);
    //((Cube*)meshes[1])->rotate(0.0f, 0.6f, 0.6f);
    //((Cube*)meshes[2])->rotate(0.6f, 0.0f, 0.0f);

    //float time = glfwGetTime() * 1.5f;
    //float dim = 0.6f;
    //glClearColor(dim*std::sin(time), dim*std::sin(time-(2*M_PI/3)), dim*std::sin(time-(4*M_PI/3)), 1.0f);

    camera.offsetLocal(camX, camY, camZ);
    
    // Render frame
    renderer.render();
}

void End() {
    
}
};

int main(void) {
    gl0::Init("Learn OpenGL", 800, 600);
    return 0;
}