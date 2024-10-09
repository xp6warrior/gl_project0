#pragma once
#include "mesh.hpp"
#include "camera.hpp"
#include <vector>

class Renderer {
private:
    std::vector<Mesh> m_meshes;
    Camera* m_camera;

public:
    void addMesh(Mesh mesh);
    void addCamera(Camera& camera);
    void render();
};