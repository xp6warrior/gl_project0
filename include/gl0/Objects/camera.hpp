#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <glm/glm.hpp>

class Camera {
private:
    glm::vec3 m_position = glm::vec3(0.f);
    glm::vec3 m_lookPosition = glm::vec3(0.f, 0.f, -1.f);

    glm::vec3 m_front;
    glm::vec3 m_right;
    static constexpr glm::vec3 m_up = glm::vec3(0.f, 1.f, 0.f);
    double m_yaw, m_pitch;

    glm::mat4 m_view_matrix;
    glm::mat4 m_proj_matrix;

    float m_max_pitch = 1.5f;

public:
    Camera();
    Camera(float x, float y, float z);
    Camera(float x, float y, float z, float look_x, float look_y, float look_z);

    void setProjectionParams(float fov, float aspect_ratio, float near, float far);

    void setPosition(float x, float y, float z); // Sets global axis position
    void setLookPosition(float x, float y, float z); // Sets local axis offset (takes rotation into account)
    void offset(float x, float y, float z); // Sets global axis look position
    void offsetLocal(float x, float y, float z); // Sets global axis offset
    void rotate(double yaw, double pitch); // Sets local axis rotation (offsets m_yaw/m_pitch by yaw/pitch)

    glm::mat4 getViewMatrix();
    glm::mat4 getProjMatrix();
};