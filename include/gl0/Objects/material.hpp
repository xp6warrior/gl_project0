#pragma once
#include "shader.hpp"
#include "texture.hpp"
#include <array>

class Material {
private:
    unsigned int m_shader_id;
    std::array<unsigned int, 16> m_textures = {0};

public:
    Material() = default;
    Material(unsigned int shader_id);
    void addTexture(unsigned int texture_id, unsigned int index);
    unsigned int getShaderID();
    std::array<unsigned int, 16> getTextureIDs();
};