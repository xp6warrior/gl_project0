#pragma once
#include "../Objects/mesh.hpp"
#include "../Objects/shaderProgram.hpp"
#include <glm/glm.hpp>

class Cube : public Mesh {
private:
    glm::mat4 m_model;

    inline static float cubeVerts[40] = {
        // Verticies            // Texture Coords
        -0.5f,  0.5f, 0.5f,     0.0f, 1.0f,
         0.5f,  0.5f, 0.5f,     1.0f, 1.0f,
         0.5f, -0.5f, 0.5f,     1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f,     0.0f, 0.0f,

        -0.5f,  0.5f, -0.5f,    0.0f, 0.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 0.0f,
         0.5f, -0.5f, -0.5f,    1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    0.0f, 1.0f
    };
    inline static unsigned int cubeIndi[36] = {
        0, 1, 2,
        2, 3, 0,
        0, 4, 1,
        1, 4, 5,
        1, 5, 2,
        2, 5, 6,
        2, 6, 3,
        3, 6, 7,
        3, 7, 0,
        0, 7, 4,
        4, 5, 6,
        6, 7, 4
    };

public:
    Cube() = default;
    Cube(ShaderProgram shader);
    void translate(float x, float y, float z);
    void rotate(float x_axis, float y_axis, float z_axis);
    void scale(float factor);
    void scale(float x, float y, float z);
};