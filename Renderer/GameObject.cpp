#include "GameObject.h"


GameObject::GameObject(Mesh *mesh) : m_pMesh(mesh)
{
	m_transformMatrix = glm::mat4();
	m_fRotDegree = 0;
}


GameObject::~GameObject()
{
}

void GameObject::cleanUp()
{
	m_pMesh->cleanUp();
}

void GameObject::render(Camera *camera, glm::vec3 lightSource)
{
	glUseProgram(m_program);
	
	GLint matLoc = glGetUniformLocation(m_program, "projViewMat");
	glUniformMatrix4fv(matLoc, 1, GL_FALSE, glm::value_ptr(camera->getViewAndProjMatrix()));

	GLint transLocation = glGetUniformLocation(m_program, "transformMatrix");
	glUniformMatrix4fv(transLocation, 1, GL_FALSE, glm::value_ptr(m_transformMatrix));

	GLint normaltransLocation = glGetUniformLocation(m_program, "normalTransformMatrix");
	glUniformMatrix4fv(normaltransLocation, 1, GL_FALSE, glm::value_ptr(m_normalTransMatrix));
	
	GLint lightLoc = glGetUniformLocation(m_program, "lightSource");
	glUniform3fv(lightLoc, 1, glm::value_ptr(lightSource));

	glBindVertexArray(m_pMesh->getVAOHandle());
	//glDrawElements(GL_TRIANGLE_STRIP, m_pMesh->getNumElements(), GL_UNSIGNED_SHORT, 0);
	glDrawArrays(GL_TRIANGLES, 0, m_pMesh->getNumVerts());
	glBindVertexArray(0);
	glUseProgram(0);
}

void GameObject::setProgram(const GLuint program)
{
	m_program = program;
}

void GameObject::update(float deltaTime)
{
	m_transformMatrix = glm::rotate(m_transformMatrix, deltaTime * .001f, glm::vec3(0.0f, 1.0f, 0.0f));
	m_normalTransMatrix = glm::transpose(glm::inverse(m_transformMatrix));
}