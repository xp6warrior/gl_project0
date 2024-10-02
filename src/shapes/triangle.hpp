#pragma once
#include "../objects/shaderProgram.hpp"
#include "../objects/mesh.hpp"

class Triangle : public Mesh {
private:
    inline static float m_verts[9] = {
         0.0f,  0.25f,  0.0f,
         0.25f, -0.25f, 0.0f,
        -0.25f, -0.25f, 0.0f
    };
    inline static unsigned int m_indices[3] = {
        0, 1, 2
    };

public:
    Triangle(float xPos, float yPos, ShaderProgram shaderProgram) : Mesh(m_verts, sizeof(m_verts), m_indices, sizeof(m_indices), shaderProgram) {
        shaderProgram.updateUniform("offset", xPos, yPos, 0.0f);
    }
};