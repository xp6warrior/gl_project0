#include <Objects/renderer.hpp>
#include <Objects/texture.hpp>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

Renderer::Renderer(Mesh* meshes, unsigned int numOfMeshes) : m_meshes(meshes), m_numOfMeshs(numOfMeshes) {
    m_projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
};

void Renderer::addCamera(Camera& camera) {
    m_camera = &camera;
}

void Renderer::render() {
    for (int i=0; i<m_numOfMeshs; i++) {
        Mesh m = m_meshes[i];
        
        Texture* textures = m.getTextures(); // 2. Configures texture samplers
        for (int i=0; i<16; i++) {
            if (textures+i == nullptr) continue;
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, textures[i].getTexture());
        }

        //glUseProgram(m.getShader().getProgram()); // 1. Enable shaderProgram is in updateUniform method
        m.getShader().updateUniform("view", glm::value_ptr(m_camera->getViewMatrix()));
        m.getShader().updateUniform("projection", glm::value_ptr(m_projection));
        glBindVertexArray(m.getVAO()); // 2. Bind VAO
        glDrawElements(GL_TRIANGLES, m.getNumOfIndicies(), GL_UNSIGNED_INT, 0); // 3. Draw
    }
}

// View matrix converts global coords to relative camera coords
// Projection matrix converts relative camera coords to normalize screen space coords