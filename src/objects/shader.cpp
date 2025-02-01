#include <iostream>
#include <gl0/Objects/shader.hpp>
#include <gl0/Objects/shaderParser.hpp>
#include <glad/glad.h>

Shader::Shader(const std::string& vert_path, const std::string& frag_path) {
    addShaderSource(GL_VERTEX_SHADER, vert_path);
    addShaderSource(GL_FRAGMENT_SHADER, frag_path);
    createProgram();
}

void Shader::addShaderSource(unsigned int type, const std::string& path) {
    // Compile
    unsigned int shader = glCreateShader(type);
    std::string src = shaderParser(path);
    const char* c_src = src.c_str();
    glShaderSource(shader, 1, &c_src, NULL);
    glCompileShader(shader);

    // Error handling
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR: " << ((type == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT")
            << " SHADER COMPILE ERROR\n" << infoLog << std::endl;
    }
    
    switch (type) {
        case GL_VERTEX_SHADER:
            m_vert = shader;
            break;
        case GL_FRAGMENT_SHADER:
            m_frag = shader;
            break;
    }
}

unsigned int Shader::createProgram() {
    // Linking
    m_id = glCreateProgram();
    glAttachShader(m_id, m_vert);
    glAttachShader(m_id, m_frag);
    glLinkProgram(m_id);

    // Error handling
    int success;
    char infoLog[512];
    glGetProgramiv(m_id, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(m_id, 512, NULL, infoLog);
        std::cout << "ERROR: SHADER PROGRAM LINK ERROR\n" << infoLog << std::endl;
    }

    glDeleteShader(m_vert);
    glDeleteShader(m_frag);

    return m_id;
}

unsigned int Shader::getShaderID() {
    return m_id;
}