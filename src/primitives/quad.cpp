#include <Primitives/quad.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Quad::Quad(ShaderProgram shader) : Mesh(m_verts, sizeof(m_verts), m_indices, sizeof(m_indices), shader) {
    m_shader = shader;
    m_model = glm::mat4(1.0f);
    this->addAttribute(0, 3, 5, 0);
    this->addAttribute(2, 2, 5, 3);
}

/*void Quad::translate(float x, float y, float z) {
    m_model = glm::translate(m_model, glm::vec3(x, y, z));
    m_shader.updateUniform("local", glm::value_ptr(m_model));
}

void Quad::rotate(float x_axis, float y_axis, float z_axis) {
    m_model = glm::rotate(m_model, glm::radians(x_axis), glm::vec3(1.0f, 0.0f, 0.0f));
    m_model = glm::rotate(m_model, glm::radians(y_axis), glm::vec3(0.0f, 1.0f, 0.0f));
    m_model = glm::rotate(m_model, glm::radians(z_axis), glm::vec3(0.0f, 0.0f, 1.0f));
    m_shader.updateUniform("local", glm::value_ptr(m_model));
}

void Quad::scale(float factor) {
    m_model = glm::scale(m_model, glm::vec3(factor, factor, factor));
    m_shader.updateUniform("local", glm::value_ptr(m_model));
}
void Quad::scale(float x, float y, float z) {
    m_model = glm::scale(m_model, glm::vec3(x, y, z));
    m_shader.updateUniform("local", glm::value_ptr(m_model));
}*/