#include <gl0/Objects/mesh.hpp>
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

Mesh::Mesh(float* vertices, unsigned int vert_len, unsigned int* indices, unsigned int indi_len, const Material& material) : m_material(material), m_num_of_indicies(indi_len / sizeof(unsigned int)) {
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
}

int Mesh::addAttribute(int index, int size, int stride, int offset) {
    if (m_VAO == 0) {
        std::cout << "ERROR: Can't add attribute to mesh without a defined VAO\n";
        return -1;
    }
    glBindVertexArray(m_VAO);                                                                                       // 1. Bind VAO
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride*sizeof(float), (void*)(offset*sizeof(float)));    // 2. Add an attribute pointer
    glEnableVertexAttribArray(index);                                                                               // 3. Enable the arribute
    return 0;
}

unsigned int Mesh::getVAO() { return m_VAO; }

unsigned int Mesh::getNumOfIndicies() { return m_num_of_indicies; }

Material Mesh::getMaterial() { return m_material; }

glm::mat4 Mesh::getLocalMatrix() { return m_model; }


void Mesh::translate(float x, float y, float z) {
    m_model = glm::translate(m_model, glm::vec3(x, y, z));
}

void Mesh::rotate(float x_axis, float y_axis, float z_axis) {
    m_model = glm::rotate(m_model, glm::radians(x_axis), glm::vec3(1.0f, 0.0f, 0.0f));
    m_model = glm::rotate(m_model, glm::radians(y_axis), glm::vec3(0.0f, 1.0f, 0.0f));
    m_model = glm::rotate(m_model, glm::radians(z_axis), glm::vec3(0.0f, 0.0f, 1.0f));
}

void Mesh::scale(float factor) {
    m_model = glm::scale(m_model, glm::vec3(factor, factor, factor));
}
void Mesh::scale(float x, float y, float z) {
    m_model = glm::scale(m_model, glm::vec3(x, y, z));
}