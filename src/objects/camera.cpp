#include <gl0/Objects/camera.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

Camera::Camera() {
    setLookPosition(m_lookPosition.x, m_lookPosition.y, m_lookPosition.z); // defines front, right, pitch and yaw
    m_proj_matrix = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

Camera::Camera(float x, float y, float z) : Camera::Camera() {
    m_position = vec3(x, y, z);
}

Camera::Camera(float x, float y, float z, float look_x, float look_y, float look_z) : Camera::Camera() {
    m_position = vec3(x, y, z);
    m_lookPosition = vec3(look_x, look_y, look_z);
}

void Camera::setProjectionParams(float fov, float aspect_ratio, float near, float far) {
    m_proj_matrix = glm::perspective(glm::radians(fov), aspect_ratio, near, far);
}

// Sets global axis position
void Camera::setPosition(float x, float y, float z) {
    m_position = vec3(x, y, z);
    m_view_matrix = glm::lookAt(m_position, m_position + m_front, m_up);
}

// Sets global axis look position
void Camera::setLookPosition(float x, float y, float z) {
    m_lookPosition = vec3(x, y, z);
    m_front = glm::normalize(m_lookPosition - m_position);

    vec3 frontNOY = vec3(m_front.x, 0.f, m_front.z);

    // Check if facing directly up or directly down (this if prevents divide by 0)
    if (m_front.x == 0 && m_front.z == 0) {
        // Adds by small value 1 to invoke pitch correction
        m_pitch = (m_max_pitch + 1) * m_front.y; // m_front.y is +1 or -1 in this situation
    } 
    else {
        // Calculate m_yaw and m_pitch according to new m_front
        m_yaw = std::acos(glm::dot(frontNOY, vec3(0.f, 0.f, 1.f))/glm::length(frontNOY));
        if (m_front.x < 0)
            m_yaw = 2*M_PI - m_yaw;
    
        m_pitch = std::acos(glm::dot(m_front, frontNOY)/glm::length(frontNOY));
        if (m_front.y < 0)
            m_pitch *= -1;
    }

    // Pitch correction
    if (m_pitch > m_max_pitch) {
        m_pitch = m_max_pitch;
        m_front.x = std::sin(m_yaw) * std::cos(m_pitch);
        m_front.y = std::sin(m_pitch);
        m_front.z = std::cos(m_yaw) * std::cos(m_pitch);
    }
    else if (m_pitch < -m_max_pitch) {
        m_pitch = -m_max_pitch;
        m_front.x = std::sin(m_yaw) * std::cos(m_pitch);
        m_front.y = std::sin(m_pitch);
        m_front.z = std::cos(m_yaw) * std::cos(m_pitch);
    }

    m_right = glm::normalize(glm::cross(m_front, m_up));
    m_view_matrix = glm::lookAt(m_position, m_position + m_front, m_up);
}

// Sets global axis offset
void Camera::offset(float x, float y, float z) {
    m_position += vec3(x, y, z);
    m_view_matrix = glm::lookAt(m_position, m_position + m_front, m_up);
}

// Sets local axis offset (takes rotation into account)
void Camera::offsetLocal(float x, float y, float z) {
    m_position += m_front * z + m_right * x + m_up * y;
    m_view_matrix = glm::lookAt(m_position, m_position + m_front, m_up);
}

// Sets local axis rotation (offsets m_yaw/m_pitch by yaw/pitch)
void Camera::rotate(double yaw, double pitch) {
    m_yaw -= yaw;
    m_pitch += pitch;
    if (m_pitch > m_max_pitch)
        m_pitch = m_max_pitch;
    else if (m_pitch < -m_max_pitch)
        m_pitch = -m_max_pitch;

    m_front.x = std::sin(m_yaw) * std::cos(m_pitch);
    m_front.y = std::sin(m_pitch);
    m_front.z = std::cos(m_yaw) * std::cos(m_pitch);

    m_right = glm::normalize(glm::cross(m_front, m_up));
    m_view_matrix = glm::lookAt(m_position, m_position + m_front, m_up);
}

glm::mat4 Camera::getViewMatrix() {
    return m_view_matrix;
}

glm::mat4 Camera::getProjMatrix() {
    return m_proj_matrix;
}