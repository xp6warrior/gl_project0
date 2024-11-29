#pragma once

#include "Objects/camera.hpp"
#include "Objects/mesh.hpp"
#include "Objects/renderer.hpp"
#include "Objects/shaderProgram.hpp"
#include "Objects/texture.hpp"
#include "Primitives/cube.hpp"
#include "Primitives/quad.hpp"

namespace gl0 {
    void Start();
    void Update();
    void End();

    void getKeyInput(int key, int action);
    void getCursorInput(double xpos, double ypos);

    int Init(std::string title, int width, int height);
}