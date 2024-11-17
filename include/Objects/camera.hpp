#pragma once
#include <glm/glm.hpp>

class Camera {
public:
    glm::vec3 m_position;
    glm::vec3 m_lookPosition;

    glm::vec3 m_front;
    glm::vec3 m_right;
    glm::vec3 m_up;

    glm::mat4 m_viewMatrix;
    float m_yaw, m_pitch;
    float m_maxPitch = 1.5f;

public:
    Camera();
    void setPosition(float x, float y, float z);
    void offset(float x, float y, float z);
    void offsetLocal(float x, float y, float z);
    void setLookPosition(float x, float y, float z);
    void rotate(float yaw, float pitch);
    glm::vec3 getPosition();
    glm::mat4 getViewMatrix();
};