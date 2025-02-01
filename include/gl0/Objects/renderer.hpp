#pragma once
#include "mesh.hpp"
#include "camera.hpp"

class Renderer {
private:
    Mesh** m_meshes;
    unsigned int m_num_of_meshs = 0;
    Camera* m_camera;

public:
    Renderer() = default;
    Renderer(Mesh** meshes, unsigned int num_of_meshes);

    void setCamera(Camera& camera);
    void render();
};