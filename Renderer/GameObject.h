#pragma once
#include "RenderAble.h"
#include "Mesh.h"
#include <GL\GL.h>
class GameObject : public RenderAble
{
public:
	GameObject(Mesh *mesh);
	~GameObject();
	void render();
	void cleanUp();
	void setProgram(const GLuint program);
	
private:

public:

private:
	GLuint m_program;
	Mesh *m_pMesh;

};

