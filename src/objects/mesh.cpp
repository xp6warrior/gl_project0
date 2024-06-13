#include "mesh.hpp"

Mesh::Mesh(float* vertices, unsigned int vert_len, unsigned int* indices, unsigned int indi_len, ShaderProgram shaderProgram) {
    // Create buffers
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_EBO);
    glGenBuffers(1, &m_VBO);
    // Bind VAO
    glBindVertexArray(m_VAO);
    // Set up VAO properties (VBO, EBO, attributes)
    // VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, vert_len, vertices, GL_STATIC_DRAW);
    // EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indi_len, indices, GL_STATIC_DRAW);
    // Attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    m_shader = shaderProgram;
    m_vert_count = vert_len/(3*sizeof(float));
}

unsigned int Mesh::getVertCount() {
    return m_vert_count;
}

unsigned int Mesh::getVAO() {
    return m_VAO;
}

unsigned int Mesh::getShader() {
    return m_shader.getProgram();
}