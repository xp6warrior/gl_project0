#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "renderer.hpp"

void Renderer::addMesh(Mesh mesh) {
    m_meshes.push_back(mesh);
}

void Renderer::render() {
    for (auto& m : m_meshes) {
        glUseProgram(m.getShader()); // 1. Enable shaderProgram
        glBindVertexArray(m.getVAO()); // 2. Bind VAO
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); // 3. Draw
    }
}