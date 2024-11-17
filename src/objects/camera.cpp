#define _USE_MATH_DEFINES
#include <cmath>

#include <Objects/camera.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

using namespace glm;

Camera::Camera() {
    m_position = vec3(0.f, 0.f, 0.f); 
    m_front = vec3(1.f, 0.f, 0.f);
    m_right = vec3(0.f, 0.f, 1.f);
    m_up = vec3(0.f, 1.f, 0.f);
    m_yaw = M_PI/2;
    m_pitch = 0.f;

    m_viewMatrix = glm::lookAt(m_position, m_position + m_front, m_up);
}

void Camera::setPosition(float x, float y, float z) { // global axis
    m_position = vec3(x, y, z);
    m_viewMatrix = glm::lookAt(m_position, m_position + m_front, m_up);
}

void Camera::setLookPosition(float x, float y, float z) { // global axis
    m_front = glm::normalize(vec3(x, y, z) - m_position);

    vec3 frontNO_Y = vec3(m_front.x, 0.f, m_front.z);

    // Facing directly up or directly down (this if prevents divide by 0)
    if (m_front.x == 0 && m_front.z == 0) {
        // add by small value 1 to invoke pitch correction
        m_pitch = (m_maxPitch + 1) * m_front.y; // m_front.y is +1 or -1 in this situation
    } 
    else {
        m_yaw = std::acos(glm::dot(frontNO_Y, vec3(0.f, 0.f, 1.f))/glm::length(frontNO_Y));
        if (m_front.x < 0)
            m_yaw = 2*M_PI - m_yaw;
    
        m_pitch = std::acos(glm::dot(m_front, frontNO_Y)/glm::length(frontNO_Y));
        if (m_front.y < 0)
            m_pitch *= -1;
    }

    // Pitch correction
    if (m_pitch > m_maxPitch) {
        m_pitch = m_maxPitch;
        m_front.x = std::sin(m_yaw) * std::cos(m_pitch);
        m_front.y = std::sin(m_pitch);
        m_front.z = std::cos(m_yaw) * std::cos(m_pitch);
    }
    else if (m_pitch < -m_maxPitch) {
        m_pitch = -m_maxPitch;
        m_front.x = std::sin(m_yaw) * std::cos(m_pitch);
        m_front.y = std::sin(m_pitch);
        m_front.z = std::cos(m_yaw) * std::cos(m_pitch);
    }

    m_right = glm::normalize(glm::cross(m_front, m_up));
    m_viewMatrix = glm::lookAt(m_position, m_position + m_front, m_up);
}

void Camera::offset(float x, float y, float z) { // global axis
    m_position += vec3(x, y, z);
    m_viewMatrix = glm::lookAt(m_position, m_position + m_front, m_up);
}

void Camera::offsetLocal(float x, float y, float z) { // local axis
    m_position += m_front * z + m_right * x + m_up * y;
    m_viewMatrix = glm::lookAt(m_position, m_position + m_front, m_up);
}

void Camera::rotate(float yaw, float pitch) { // local axis
    m_yaw -= yaw;
    m_pitch += pitch;
    if (m_pitch > m_maxPitch)
        m_pitch = m_maxPitch;
    else if (m_pitch < -m_maxPitch)
        m_pitch = -m_maxPitch;

    m_front.x = std::sin(m_yaw) * std::cos(m_pitch);
    m_front.y = std::sin(m_pitch);
    m_front.z = std::cos(m_yaw) * std::cos(m_pitch);

    m_right = glm::normalize(glm::cross(m_front, m_up));
    m_viewMatrix = glm::lookAt(m_position, m_position + m_front, m_up);
}

vec3 Camera::getPosition() {
    return m_position;
}

mat4 Camera::getViewMatrix() {
    return m_viewMatrix;
}