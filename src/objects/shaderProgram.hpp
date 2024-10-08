#pragma once
#include <string>

class ShaderProgram {
private:
    unsigned int m_vert;
    unsigned int m_frag;
    unsigned int m_program;

public:
    ShaderProgram() = default;
    ShaderProgram(std::string vert_src, std::string frag_src);
    void addShader(unsigned int type, std::string src);
    void createProgram();
    unsigned int getProgram();
    void updateUniform(std::string name, float f);
    void updateUniform(std::string name, float f1, float f2, float f3);
    void updateUniform(std::string name, const float *matrix);
};