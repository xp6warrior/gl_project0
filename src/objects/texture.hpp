#pragma once
#include <string>

class Texture {
private:
    unsigned int m_texture;
    int m_width, m_height, m_nrChannels;
    unsigned char *m_data;

public:
    Texture();
    int loadTexture(std::string path, int format);
    unsigned int getTexture();
};