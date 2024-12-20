#include <Objects/mesh.hpp>
#include <glad/glad.h>

Mesh::Mesh(float* vertices, unsigned int vert_len, unsigned int* indices, unsigned int indi_len, ShaderProgram shaderProgram) : m_shader(shaderProgram), m_numOfIndicies(indi_len / sizeof(unsigned int)) {
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

void Mesh::addAttribute(int index, int size, int stride, int offset) {
    glBindVertexArray(m_VAO);                                                                                       // 1. Bind VAO
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride*sizeof(float), (void*)(offset*sizeof(float)));    // 2. Add an attribute pointer
    glEnableVertexAttribArray(index);                                                                               // 3. Enable the arribute
}

void Mesh::addTexture(unsigned int index, Texture texture) {
    m_textures[index] = texture;                                                                                // 1. Add texture to textures array (based on index)
    glUseProgram(m_shader.getProgram());
    glUniform1i(glGetUniformLocation(m_shader.getProgram(), ("tex" + std::to_string(index)).c_str()), index);   // 3. Set texture sampler uniform
}

Texture* Mesh::getTextures() {
    return m_textures;
}

unsigned int Mesh::getVAO() {
    return m_VAO;
}

ShaderProgram Mesh::getShader() {
    return m_shader;
}

unsigned int Mesh::getNumOfIndicies() {
    return m_numOfIndicies;
}


void Mesh::translate(float x, float y, float z) {
    m_model = glm::translate(m_model, glm::vec3(x, y, z));
    m_shader.updateUniform("local", glm::value_ptr(m_model));
}

void Mesh::rotate(float x_axis, float y_axis, float z_axis) {
    m_model = glm::rotate(m_model, glm::radians(x_axis), glm::vec3(1.0f, 0.0f, 0.0f));
    m_model = glm::rotate(m_model, glm::radians(y_axis), glm::vec3(0.0f, 1.0f, 0.0f));
    m_model = glm::rotate(m_model, glm::radians(z_axis), glm::vec3(0.0f, 0.0f, 1.0f));
    m_shader.updateUniform("local", glm::value_ptr(m_model));
}

void Mesh::scale(float factor) {
    m_model = glm::scale(m_model, glm::vec3(factor, factor, factor));
    m_shader.updateUniform("local", glm::value_ptr(m_model));
}
void Mesh::scale(float x, float y, float z) {
    m_model = glm::scale(m_model, glm::vec3(x, y, z));
    m_shader.updateUniform("local", glm::value_ptr(m_model));
}