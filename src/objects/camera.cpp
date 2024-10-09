#include "camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

using namespace glm;

Camera::Camera(vec3 pos, vec3 lookAt) {
    m_position = pos;
    m_lookPosition = lookAt;
}

void Camera::translate(vec3 pos) {
    m_position = pos;
    m_viewMatrix = glm::lookAt(m_position, m_lookPosition, glm::vec3(0.f, 1.f, 0.f));
}

void Camera::offset(vec3 offset) {
    m_position += offset;
    m_viewMatrix = glm::lookAt(m_position, m_lookPosition, glm::vec3(0.f, 1.f, 0.f));
}

void Camera::translateLookPos(vec3 lookPos) {
    m_lookPosition = lookPos;
    m_viewMatrix = glm::lookAt(m_position, m_lookPosition, glm::vec3(0.f, 1.f, 0.f));
}

void Camera::rotate(float yaw, float pitch) {
    vec3 offset;
    offset.x = std::sin(glm::radians(yaw)) * std::cos(glm::radians(pitch));
    offset.y = std::sin(glm::radians(pitch));
    offset.z = std::cos(glm::radians(yaw)) * std::cos(glm::radians(pitch));
    m_lookPosition = m_position + offset;
    m_viewMatrix = glm::lookAt(m_position, m_lookPosition, glm::vec3(0.f, 1.f, 0.f));
}

vec3 Camera::getPosition() {
    return m_position;
}

mat4 Camera::getViewMatrix() {
    return m_viewMatrix;
}