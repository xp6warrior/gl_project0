#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>

#include "renderer.hpp"
#include "texture2D.hpp"

void Renderer::addMesh(Mesh mesh) {
    m_meshes.push_back(mesh);
}

void Renderer::render() {
    for (auto& m : m_meshes) {
        
        Texture2D* textures = m.getTextures(); // 2. Configures texture samplers
        for (int i=0; i<16; i++) {
            if (textures+i == nullptr) continue;
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, textures[i].getTexture());
        }

        glUseProgram(m.getShader()); // 1. Enable shaderProgram
        glBindVertexArray(m.getVAO()); // 2. Bind VAO
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); // 3. Draw
    }
}