#pragma once
#include "../objects/mesh.hpp"
#include "../objects/shaderProgram.hpp"
#include <glm/glm.hpp>

class Quad : public Mesh {
protected:
    ShaderProgram m_shader;
    glm::mat4 m_model;

    inline static float m_verts[20] = {
         0.5f,  0.5f, 0.0f,     1.0f, 1.0f,
         0.5f, -0.5f, 0.0f,     1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,     0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f,     0.0f, 1.0f
    };
    inline static unsigned int m_indices[6] = {
        0, 1, 3,
        1, 2, 3
    };

public:
    Quad() = default;
    Quad(ShaderProgram shaderProgram);
    void translate(float x, float y, float z);
    void rotate(float x_axis, float y_axis, float z_axis);
    void scale(float factor);
    void scale(float x, float y, float z);
};