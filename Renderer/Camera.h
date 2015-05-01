#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
class Camera
{
public:
	Camera(glm::vec3 position, glm::vec3 direction);
	~Camera();

	glm::mat4 getViewAndProjMatrix() const;
	void setPosition(glm::vec3 newPos);
	void updatePosition(float movementScalar);
private:
	void updateViewMatrix();
public:

private:
	glm::vec3 m_position;
	glm::vec3 m_direction;
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projMatrix;
};

