#include "Mesh.h"


Mesh::Mesh(glm::vec3 *vertices, int numVerts) : m_verticesPos(vertices), m_iNumVerts(numVerts)
{
	m_vertexArrayObj = 0;
	m_verticesColor = m_verticesNor = nullptr;
	m_vecticesTexCoords = nullptr;
}


Mesh::~Mesh()
{
}

void Mesh::cleanUp()
{
	if (m_vertexArrayObj == 0)
	{
		glDeleteBuffers(1, &m_vertexArrayObj);
	}
}


GLuint Mesh::getVAOHandle() const
{
	return m_vertexArrayObj;
}


int Mesh::getNumVerts() const
{
	return m_iNumVerts;
}

void Mesh::initBufferFromData()
{
	
	glCreateVertexArrays(1, &m_vertexArrayObj);
	glBindVertexArray(m_vertexArrayObj);
	GLuint posBuffer;
	GLuint colBuffer;
	glCreateBuffers(1, &posBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * m_iNumVerts, m_verticesPos, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

