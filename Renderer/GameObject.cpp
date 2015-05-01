#include "GameObject.h"


GameObject::GameObject(Mesh *mesh) : m_pMesh(mesh)
{
}


GameObject::~GameObject()
{
}

void GameObject::cleanUp()
{
	m_pMesh->cleanUp();
}

void GameObject::render()
{
	glUseProgram(m_program);
	glBindVertexArray(m_pMesh->getVAOHandle());
	glDrawElements(GL_TRIANGLE_STRIP, m_pMesh->getNumElements(), GL_UNSIGNED_SHORT, 0);
	glBindVertexArray(0);
	glUseProgram(0);
}

void GameObject::setProgram(const GLuint program)
{
	m_program = program;
}