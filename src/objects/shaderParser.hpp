#pragma once
#include <fstream>
#include <sstream>
#include <string>

std::string shaderParser(std::string path) {
    std::ifstream file;
    std::stringstream sstream;

    file.open(path);
    sstream << file.rdbuf();
    file.close();

    return sstream.str();
}