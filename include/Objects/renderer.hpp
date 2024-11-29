#pragma once
#include "mesh.hpp"
#include "camera.hpp"
#include <glm/glm.hpp>

class Renderer {
private:
    Mesh** m_meshes;
    unsigned int m_numOfMeshs;
    Camera* m_camera;
    glm::mat4 m_projection;

public:
    Renderer() = default;
    Renderer(Mesh** meshes, unsigned int numOfMeshes);
    void addCamera(Camera& camera);
    void render();
};