#pragma once
#include <string>

class Shader {
private:
    unsigned int m_vert;
    unsigned int m_frag;
    unsigned int m_id;

public:
    Shader() = default;
    Shader(const std::string& vert_path, const std::string& frag_path);
    void addShaderSource(unsigned int type, const std::string& path);
    unsigned int createProgram();
    unsigned int getShaderID();
};