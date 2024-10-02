#pragma once

#include "shaderProgram.hpp"
#include "texture2D.hpp"

class Mesh {
private:
    unsigned int m_VAO;
    unsigned int m_VBO;
    unsigned int m_EBO;
    ShaderProgram m_shader;
    Texture2D m_textures[16];

public:
    Mesh(float* vertices, unsigned int vert_len, unsigned int* indices, unsigned int indi_len, ShaderProgram shaderProgram);
    void addAttribute(int index, int size, int stride, int offset);
    void addTexture(unsigned int index, Texture2D texture);
    Texture2D* getTextures();
    unsigned int getVAO();
    unsigned int getShader();
};