#pragma once

#include <string>

class Texture2D {
private:
    unsigned int m_texture;
    int m_width, m_height, m_nrChannels;
    unsigned char *m_data;

public:
    Texture2D();
    int loadTexture(std::string path, int format);
    unsigned int getTexture();
};