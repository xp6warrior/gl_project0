#pragma once
#include <glm/glm.hpp>

class Camera {
public:
    glm::vec3 m_position;
    glm::vec3 m_lookPosition;
    glm::mat4 m_viewMatrix;

public:
    Camera() = default;
    Camera(glm::vec3 pos, glm::vec3 lookAt);
    void translate(glm::vec3 pos);
    void offset(glm::vec3 offset);
    void translateLookPos(glm::vec3 lookPos);
    void rotate(float yaw, float pitch);
    glm::vec3 getPosition();
    glm::mat4 getViewMatrix();
};