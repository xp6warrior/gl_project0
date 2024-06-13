#include "renderer.hpp"

void Renderer::addMesh(Mesh mesh) {
    m_meshes.push_back(mesh);
}

void Renderer::render() {
    for (auto& m : m_meshes) {
        // 1. Enable shaderProgram
        glUseProgram(m.getShader());
        // 2. Bind VAO
        glBindVertexArray(m.getVAO());
        // 3. Draw
        glDrawElements(GL_TRIANGLES, m.getVertCount(), GL_UNSIGNED_INT, 0);
    //  glDrawArrays(GL_TRIANGLES, 0, 6);
    }
}