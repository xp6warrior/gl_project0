#pragma once
#include "shaderProgram.hpp"

class Mesh {
protected:
    unsigned int m_VAO;
    unsigned int m_VBO;
    unsigned int m_EBO;
    ShaderProgram m_shader;
    unsigned int m_element_count;

public:
    Mesh(float* vertices, unsigned int vert_len, unsigned int* indices, unsigned int ind_len, ShaderProgram shaderProgram);
    unsigned int getElementCount();
    unsigned int getVAO();
    unsigned int getShader();
};