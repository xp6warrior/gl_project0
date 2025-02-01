#include <gl0/Objects/material.hpp>

Material::Material(unsigned int shader_id) : m_shader_id(shader_id) {}

void Material::addTexture(unsigned int texture_id, unsigned int index) {
    m_textures[index] = texture_id;
}

unsigned int Material::getShaderID() {
    return m_shader_id;
}

std::array<unsigned int, 16> Material::getTextureIDs() {
    return m_textures;
}