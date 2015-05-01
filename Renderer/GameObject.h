#pragma once
#include "RenderAble.h"
#include "Mesh.h"
#include <GL\GL.h>
#include <glm\gtc\type_ptr.hpp>
#include "UpdateAble.h"
#include "Camera.h"
class GameObject : public RenderAble, public Updateable
{
public:
	GameObject(Mesh *mesh);
	~GameObject();
	void render(Camera *camera);
	void cleanUp();
	void setProgram(const GLuint program);
	void update(float deltaTime);
private:

public:

private:
	GLuint m_program;
	Mesh *m_pMesh;
	glm::mat4 m_transformMatrix;
	float m_fRotDegree;
};

