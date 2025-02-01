#pragma once
#include "../Objects/mesh.hpp"
#include "../Objects/material.hpp"
#include <glm/glm.hpp>

class Cube : public Mesh {
private:
    inline static float cube_verts[40] = {
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
    inline static unsigned int cube_indi[36] = {
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
    Cube(const Material& material);
};