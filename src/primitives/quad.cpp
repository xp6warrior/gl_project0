#include <gl0/Primitives/quad.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Quad::Quad(const Material& material) : Mesh(quad_verts, sizeof(quad_verts), quad_indices, sizeof(quad_indices), material) {
    m_model = glm::mat4(1.0f);
    this->addAttribute(0, 3, 5, 0);
    this->addAttribute(2, 2, 5, 3);
}
