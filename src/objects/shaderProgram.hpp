#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

class ShaderProgram {
private:
    unsigned int m_vert;
    unsigned int m_frag;
    unsigned int m_program;

public:
    void addShader(GLenum type, std::string& src);
    void createProgram();
    unsigned int getProgram();
    void updateUniform(std::string name, float f1, float f2, float f3);
};