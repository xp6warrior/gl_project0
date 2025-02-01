#include <gl0/Primitives/cube.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Cube::Cube(const Material& material) : Mesh(cube_verts, sizeof(cube_verts), cube_indi, sizeof(cube_indi), material) {
    m_model = glm::mat4(1.0f);
    this->addAttribute(0, 3, 5, 0);
    this->addAttribute(1, 2, 5, 3);
}