#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "shaderProgram.hpp"

ShaderProgram::ShaderProgram(std::string& vert_src, std::string& frag_src) {
    addShader(GL_VERTEX_SHADER, vert_src);
    addShader(GL_FRAGMENT_SHADER, frag_src);
    createProgram();
}

void ShaderProgram::addShader(GLenum type, std::string& src) {
    // Compile
    unsigned int shader = glCreateShader(type);
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

void ShaderProgram::createProgram() {
    // Linking
    m_program = glCreateProgram();
    glAttachShader(m_program, m_vert);
    glAttachShader(m_program, m_frag);
    glLinkProgram(m_program);

    // Error handling
    int success;
    char infoLog[512];
    glGetProgramiv(m_program, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(m_program, 512, NULL, infoLog);
        std::cout << "ERROR: SHADER PROGRAM LINK ERROR\n" << infoLog << std::endl;
    }

    glDeleteShader(m_vert);
    glDeleteShader(m_frag);
}

unsigned int ShaderProgram::getProgram() {
    return m_program;
}

void ShaderProgram::updateUniform(std::string name, float f) {
    unsigned int uniformLoc = glGetUniformLocation(m_program, name.c_str());
    glUseProgram(m_program);
    glUniform1f(uniformLoc, f);
}

void ShaderProgram::updateUniform(std::string name, float f1, float f2, float f3) {
    unsigned int uniformLoc = glGetUniformLocation(m_program, name.c_str());
    glUseProgram(m_program);
    glUniform3f(uniformLoc, f1, f2, f3);
}

void ShaderProgram::updateUniform(std::string name, float *matrix) {
    unsigned int uniformLoc = glGetUniformLocation(m_program, name.c_str());
    glUseProgram(m_program);
    glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, matrix);
}