#pragma once
#include "shaderProgram.hpp"
#include "texture.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Mesh {
protected:
    unsigned int m_VAO;
    unsigned int m_VBO;
    unsigned int m_EBO;
    unsigned int m_numOfIndicies;
    ShaderProgram m_shader;
    Texture m_textures[16];
    glm::mat4 m_model;

public:
    Mesh() = default;
    Mesh(float* vertices, unsigned int vert_len, unsigned int* indices, unsigned int indi_len, ShaderProgram shaderProgram);
    void addAttribute(int index, int size, int stride, int offset);
    void addTexture(unsigned int index, Texture texture);
    Texture* getTextures();
    unsigned int getVAO();
    ShaderProgram getShader();
    unsigned int getNumOfIndicies();

    void translate(float x, float y, float z);
    void rotate(float x_axis, float y_axis, float z_axis);
    void scale(float factor);
    void scale(float x, float y, float z);
};