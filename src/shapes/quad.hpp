#pragma once
#include "../objects/shaderProgram.hpp"
#include "../objects/mesh.hpp"

class Quad : public Mesh {
protected:
    inline static float m_verts[12] = {
         0.25f,  0.25f, 0.0f,
         0.25f, -0.25f, 0.0f,
        -0.25f, -0.25f, 0.0f,
        -0.25f,  0.25f, 0.0f
    };
    inline static unsigned int m_indices[6] = {
        0, 1, 3,
        1, 2, 3
    };

public:
    Quad(float xPos, float yPos, float scale, ShaderProgram shaderProgram) : Mesh(m_verts, sizeof(m_verts), m_indices, sizeof(m_indices), shaderProgram) {
        shaderProgram.updateUniform("scale", scale);
        shaderProgram.updateUniform("offset", xPos, yPos, 0.0f);
    }
};