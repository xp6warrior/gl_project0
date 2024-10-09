#include "renderer.hpp"
#include "texture.hpp"
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

void Renderer::addMesh(Mesh mesh) {
    m_meshes.push_back(mesh);
}

void Renderer::addCamera(Camera& camera) {
    m_camera = &camera;
}

void Renderer::render() {
    for (auto& m : m_meshes) {
        
        Texture* textures = m.getTextures(); // 2. Configures texture samplers
        for (int i=0; i<16; i++) {
            if (textures+i == nullptr) continue;
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, textures[i].getTexture());
        }

        //glUseProgram(m.getShader().getProgram()); // 1. Enable shaderProgram
        m.getShader().updateUniform("view", glm::value_ptr(m_camera->getViewMatrix()));
        glBindVertexArray(m.getVAO()); // 2. Bind VAO
        glDrawElements(GL_TRIANGLES, m.getNumOfIndicies(), GL_UNSIGNED_INT, 0); // 3. Draw
    }
}