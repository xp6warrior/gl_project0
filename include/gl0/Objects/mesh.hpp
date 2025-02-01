#pragma once
#include "material.hpp"
#include <glm/glm.hpp>

class Mesh {
protected:
    unsigned int m_VAO = 0;
    unsigned int m_VBO = 0;
    unsigned int m_EBO = 0;
    unsigned int m_num_of_indicies = 0;
    Material m_material;
    glm::mat4 m_model;

public:
    Mesh() = default;
    Mesh(float* vertices, unsigned int vert_len, unsigned int* indices, unsigned int indi_len, const Material& material);
    int addAttribute(int index, int size, int stride, int offset);
    unsigned int getVAO();
    unsigned int getNumOfIndicies();
    Material getMaterial();
    glm::mat4 getLocalMatrix();

    void translate(float x, float y, float z);
    void rotate(float x_axis, float y_axis, float z_axis);
    void scale(float factor);
    void scale(float x, float y, float z);
};