#pragma once
#include "../objects/mesh.hpp"
#include "../objects/material.hpp"
#include <glm/glm.hpp>

class Quad : public Mesh {
private:
    inline static float quad_verts[] = {
         0.5f,  0.5f, 0.0f,     1.0f, 1.0f,
         0.5f, -0.5f, 0.0f,     1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,     0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f,     0.0f, 1.0f
    };
    inline static unsigned int quad_indices[] = {
        0, 1, 3,
        1, 2, 3
    };

public:
    Quad() = default;
    Quad(const Material& material);
};