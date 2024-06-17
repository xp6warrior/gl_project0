#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "mesh.hpp"

Mesh::Mesh(float* vertices, unsigned int vert_len, unsigned int* indices, unsigned int indi_len, ShaderProgram shaderProgram) : m_shader(shaderProgram), m_element_count(indi_len) {
    // Create buffers
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_EBO);
    glGenBuffers(1, &m_VBO);
    // Bind VAO
    glBindVertexArray(m_VAO);
    // Set up VAO properties (VBO, EBO, attributes)
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO); // VBO
    glBufferData(GL_ARRAY_BUFFER, vert_len, vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO); // EBO
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indi_len, indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0); // Attributes
    glEnableVertexAttribArray(0);
}

unsigned int Mesh::getElementCount() {
    return m_element_count;
}

unsigned int Mesh::getVAO() {
    return m_VAO;
}

unsigned int Mesh::getShader() {
    return m_shader.getProgram();
}