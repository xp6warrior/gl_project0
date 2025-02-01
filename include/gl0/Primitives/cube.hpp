#pragma once
#include "../Objects/mesh.hpp"
#include "../Objects/material.hpp"
#include <glm/glm.hpp>

class Cube : public Mesh {
private:
    inline static float cube_verts[] = {
        // Verticies            // Texture Coords
        -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, // Front
         0.5f, -0.5f, -0.5f,    1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,    0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 1.0f,

         0.5f, -0.5f, -0.5f,    0.0f, 0.0f, // Right
         0.5f, -0.5f,  0.5f,    1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,    0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 1.0f,

         0.5f, -0.5f,  0.5f,    0.0f, 0.0f, // Back
        -0.5f, -0.5f,  0.5f,    1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,    1.0f, 1.0f,

        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, // Left
        -0.5f, -0.5f, -0.5f,    1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,    0.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,    1.0f, 1.0f,
        
        -0.5f,  0.5f, -0.5f,    0.0f, 0.0f, // Top
         0.5f,  0.5f, -0.5f,    1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,    0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 1.0f,

        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, // Bottom
         0.5f, -0.5f,  0.5f,    1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,    0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,    1.0f, 1.0f
    };
    inline static unsigned int cube_indi[] = {
        0, 1, 2, // Front
        2, 1, 3,
        4, 5, 6, // Right
        6, 5, 7,
        8, 9, 10, // Back
        10, 9, 11,
        12, 13, 14, // Left
        14, 13, 15,
        16, 17, 18, // Top
        18, 17, 19,
        20, 21, 22, // Bottom
        22, 21, 23
    };

public:
    Cube() = default;
    Cube(const Material& material);
};