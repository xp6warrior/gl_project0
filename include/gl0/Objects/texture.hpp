#pragma once
#include <string>

class Texture {
private:
    unsigned int m_texture;

public:
    Texture() = default;
    Texture(const std::string& path, int format);
    unsigned int getTextureID();
};