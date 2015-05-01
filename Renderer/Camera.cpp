#include "Camera.h"


Camera::Camera(glm::vec3 position, glm::vec3 direction) : m_position(position), m_direction(direction)
{
	updateViewMatrix();
	m_projMatrix = glm::perspective(45.0f, 800.0f / 600.0f, .1f, 100.0f);
}


Camera::~Camera()
{
}

glm::mat4 Camera::getViewAndProjMatrix() const
{
	return (m_projMatrix * m_viewMatrix);
}

void Camera::updateViewMatrix()
{
	m_viewMatrix = glm::lookAt(m_position, m_position + m_direction, glm::vec3(0, 1, 0));
}

void Camera::setPosition(glm::vec3 newPos)
{
	m_position = newPos;

}
void Camera::updatePosition(float movementScalar)
{
	m_position += glm::normalize(m_direction) * movementScalar;
	updateViewMatrix();
}