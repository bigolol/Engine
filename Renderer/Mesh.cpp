#include "Mesh.h"


Mesh::Mesh(Vertex *vertices, int numVerts) : m_verts(vertices), m_iNumVerts(numVerts)
{
	m_vertexArrayObj = 0;
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
	glGenVertexArrays(1, &m_vertexArrayObj);
	GLuint m_vertexBufferHandle;
	glGenBuffers(1, &m_vertexBufferHandle);
	glBindVertexArray(m_vertexArrayObj);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, m_iNumVerts * sizeof(Vertex), m_verts, GL_STATIC_DRAW);
	//position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) 0);
	//color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)sizeof(glm::vec3));
	//normal
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(glm::vec3) * 2));
	//tex
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(glm::vec2) * 3));


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}


void Mesh::bindElementArray(GLushort *element, int numElements)
{

	glGenBuffers(1, &m_vertexElementHandle);
	glBindVertexArray(m_vertexArrayObj);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexElementHandle);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numElements * sizeof(element[0]), &element[0], GL_STATIC_DRAW);

	glBindVertexArray(0);
	m_iNumElements = numElements;
}

int Mesh::getNumElements()
{
	return m_iNumElements;
}
