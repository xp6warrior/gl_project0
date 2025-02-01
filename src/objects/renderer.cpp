#include <gl0/Objects/renderer.hpp>
#include <gl0/Objects/texture.hpp>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <array>
#include <iostream>

Renderer::Renderer(Mesh** meshes, unsigned int num_of_meshes, Camera* camera) {
    m_meshes = meshes;
    m_num_of_meshs = num_of_meshes;
    m_camera = camera;
}

void Renderer::setCamera(Camera* camera) {
    m_camera = camera;
}

void Renderer::render() {
    for (unsigned int i=0; i<m_num_of_meshs; i++) {
        // Loops through all meshes
        Mesh* m = m_meshes[i];
        Material mat = m->getMaterial();
        
        // Configures texture sampler (by setting state of all textures)
        std::array<unsigned int, 16> textures = mat.getTextureIDs();
        for (auto i=0; i<textures.size(); i++) {
            if (textures[i] == 0) continue;
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, textures[i]);
        }

        // Binds shader and updates uniforms (such as view and projection matricies)
        unsigned int shader_id = mat.getShaderID();
        glUseProgram(shader_id);
        glUniformMatrix4fv(glGetUniformLocation(shader_id, "local"), 1, GL_FALSE, glm::value_ptr(m->getLocalMatrix())); // Converts local coords to global coords
        if (m_camera != nullptr) {
            glUniformMatrix4fv(glGetUniformLocation(shader_id, "view"), 1, GL_FALSE, glm::value_ptr(m_camera->getViewMatrix())); // Converts global coords to relative camera coords
            glUniformMatrix4fv(glGetUniformLocation(shader_id, "projection"), 1, GL_FALSE, glm::value_ptr(m_camera->getProjMatrix())); // Converts relative camera coords to normalize screen space coords
        } else {
            glUniformMatrix4fv(glGetUniformLocation(shader_id, "view"), 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
            glUniformMatrix4fv(glGetUniformLocation(shader_id, "projection"), 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
        }
        
        // Binds VAO and draws mesh
        glBindVertexArray(m->getVAO());
        glDrawElements(GL_TRIANGLES, m->getNumOfIndicies(), GL_UNSIGNED_INT, 0);
    }
}
