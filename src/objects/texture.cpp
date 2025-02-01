#include <iostream>
#include <gl0/Objects/texture.hpp>
#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

Texture::Texture(const std::string& path, int format) {
    stbi_set_flip_vertically_on_load(true);

    int width, height, nr_channels;
    unsigned char* data;
   
    data = stbi_load(path.c_str(), &width, &height, &nr_channels, 0);                                   // Load image data
    if (data) {
        glGenTextures(1, &m_texture);                                                                   // Generate a texture buffer
        glBindTexture(GL_TEXTURE_2D, m_texture);                                                        // Bind the texture for manipulation
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);       // Insert image data into texture
        glGenerateMipmap(GL_TEXTURE_2D);                                                                // Generate mipmaps
        stbi_image_free(data);                                                                          // Free image data
    } else {
        std::cout << "FAILED TO LOAD TEXTURE!\nPath: " << path << std::endl;
    }
}

unsigned int Texture::getTextureID() {
    return m_texture;
}