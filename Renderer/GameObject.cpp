#include "GameObject.h"


GameObject::GameObject(Mesh *mesh) : m_pMesh(mesh)
{
	glm::vec3 rotationVec(0.0f, 1.0f, 0.0f);
}


GameObject::~GameObject()
{
}

void GameObject::cleanUp()
{
	m_pMesh->cleanUp();
}

void GameObject::render(Camera *camera)
{
	glUseProgram(m_program);
	
	GLint matLoc = glGetUniformLocation(m_program, "projViewMat");
	glUniformMatrix4fv(matLoc, 1, GL_FALSE, glm::value_ptr(camera->getViewAndProjMatrix()));

	glBindVertexArray(m_pMesh->getVAOHandle());
	glDrawElements(GL_TRIANGLE_STRIP, m_pMesh->getNumElements(), GL_UNSIGNED_SHORT, 0);
	glBindVertexArray(0);
	glUseProgram(0);
}

void GameObject::setProgram(const GLuint program)
{
	m_program = program;
}