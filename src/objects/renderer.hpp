#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "mesh.hpp"

class Renderer {
private:
    std::vector<Mesh> m_meshes;

public:
    void addMesh(Mesh mesh);
    void render();
};