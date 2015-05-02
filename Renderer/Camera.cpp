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


void Camera::getNotified(int x, int y)
{

}

void Camera::move(bool directions[], float amount)
{
	//vorne
	if (directions[0])
	{
		m_position += glm::normalize(m_direction) * amount;
	}
	//hinten
	if (directions[1])
	{
		m_position -= glm::normalize(m_direction) * amount;
	}
	//rechts
	if (directions[2])
	{
		m_position += glm::normalize(glm::cross(m_direction, glm::vec3(0.0f,1.0f, 0.0f))) * amount;
	}
	//links
	if (directions[3])
	{
		m_position -= glm::normalize(glm::cross(m_direction, glm::vec3(0.0f, 1.0f, 0.0f))) * amount;
	}
	updateViewMatrix();
}