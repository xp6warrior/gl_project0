#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaderProgram.hpp"

class Mesh {
private:
    unsigned int m_VAO;
    unsigned int m_VBO;
    unsigned int m_EBO;
    ShaderProgram m_shader;
    unsigned int m_vert_count;

public:
    Mesh(float* vertices, unsigned int vert_len, unsigned int* indices, unsigned int ind_len, ShaderProgram shaderProgram);
    unsigned int getVertCount();
    unsigned int getVAO();
    unsigned int getShader();
};