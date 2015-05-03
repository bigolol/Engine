#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "Listener.h"
#include "commandable.h"
class Camera : public Listener
{
public:
	Camera(glm::vec3 position, glm::vec3 direction);
	~Camera();

	glm::mat4 getViewAndProjMatrix() const;
	glm::vec3 getPosition();
	void setPosition(glm::vec3 newPos);
	void getNotified(int x, int y);
	void cleanUp();
	void performAction(COMMANDS command);
private:
	void updateViewMatrix();
public:

private:
	glm::vec3 m_position;
	glm::vec3 m_direction;
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projMatrix;
	float m_fRotationVert;
	float m_fRotationHorizontal;
	int m_iOldX, m_iOldY;
	float m_fSpeed;
};

