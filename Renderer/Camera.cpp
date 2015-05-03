#include "Camera.h"


Camera::Camera(glm::vec3 position, glm::vec3 direction) : m_position(position), m_direction(direction),
m_iOldX(0), m_iOldY(0)
{
	//1 0 0 is the basis for rotation
	m_fRotationVert = glm::degrees(glm::asin(m_direction.y / sqrt(m_direction.x * m_direction.x + m_direction.y * m_direction.y)));
	m_fRotationHorizontal = glm::degrees(glm::asin(m_direction.z / sqrt(m_direction.z * m_direction.z + m_direction.x * m_direction.x)));
	updateViewMatrix();
	m_projMatrix = glm::perspective(45.0f, 800.0f / 600.0f, .1f, 100.0f);
	m_fSpeed = .25f;
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

glm::vec3 Camera::getPosition()
{
	return m_position;
}
void Camera::getNotified(int x, int y)
{
	float xoffset = x - m_iOldX;
	float yoffset = m_iOldY - y;
	m_iOldX = x;
	m_iOldY = y;

	float sensitivity = 0.25;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	m_fRotationHorizontal += xoffset;
	m_fRotationVert += yoffset;

	if (m_fRotationVert > 89.0f)
		m_fRotationVert = 89.0f;
	if (m_fRotationVert < -89.0f)
		m_fRotationVert = -89.0f;

	glm::vec3 front;
	front.x = cos(glm::radians(m_fRotationHorizontal)) * cos(glm::radians(m_fRotationVert));
	front.y = sin(glm::radians(m_fRotationVert));
	front.z = sin(glm::radians(m_fRotationHorizontal)) * cos(glm::radians(m_fRotationVert));
	m_direction = glm::normalize(front);

	updateViewMatrix();
}

void Camera::performAction(COMMANDS command)
{
	switch (command)
	{
	case MOVE_FORWARD:
		m_position += glm::normalize(m_direction) * m_fSpeed;
		break;
	case MOVE_BACKWARDS:
		m_position -= glm::normalize(m_direction) * m_fSpeed;
		break;
	case MOVE_LEFT:
		m_position -= glm::normalize(glm::cross(m_direction, glm::vec3(0.0f, 1.0f, 0.0f))) * m_fSpeed;
		break;
	case MOVE_RIGHT:
		m_position += glm::normalize(glm::cross(m_direction, glm::vec3(0.0f, 1.0f, 0.0f))) * m_fSpeed;
		break;
	case JUMP:
		m_position += glm::vec3(0.0f, 1.0f, 0.0f) * m_fSpeed;
		break;
	}
	updateViewMatrix();
}

void Camera::cleanUp()
{

}