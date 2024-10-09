#include "texture.hpp"
#include <glad/glad.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture() {
    stbi_set_flip_vertically_on_load(true);
}

int Texture::loadTexture(std::string path, int format) {
    m_data = stbi_load(path.c_str(), &m_width, &m_height, &m_nrChannels, 0);                            // Load image data
    if (m_data) {
        glGenTextures(1, &m_texture);                                                                   // Generate a texture buffer
        glBindTexture(GL_TEXTURE_2D, m_texture);                                                        // Bind the texture for manipulation
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, format, GL_UNSIGNED_BYTE, m_data); // Insert image data into texture
        glGenerateMipmap(GL_TEXTURE_2D);                                                                // Generate mipmaps
        stbi_image_free(m_data);                                                                        // Free image data
        return 0;
    } else {
        std::cout << "FAILED TO LOAD TEXTURE!\n";
        return -1;
    }
}

unsigned int Texture::getTexture() {
    return m_texture;
}