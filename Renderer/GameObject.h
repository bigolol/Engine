#pragma once
#include "RenderAble.h"
#include "Mesh.h"
#include <GL\GL.h>
#include <glm\gtc\type_ptr.hpp>

#include "Camera.h"
class GameObject : public RenderAble
{
public:
	GameObject(Mesh *mesh);
	~GameObject();
	void render(Camera *camera);
	void cleanUp();
	void setProgram(const GLuint program);
	
private:

public:

private:
	GLuint m_program;
	Mesh *m_pMesh;
	glm::mat4 m_transformMatrix;
};

