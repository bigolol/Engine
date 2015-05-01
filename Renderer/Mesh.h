#pragma once
#include <glm\glm.hpp>
#include <GL\glew.h>
#include <glm\gtc\type_ptr.hpp>
class Mesh
{
public:
	Mesh(glm::vec3 *vertices, int numVerts);
	~Mesh();
	void initBufferFromData();
	void cleanUp();
	GLuint getVAOHandle() const;
	int getNumVerts() const;
private:
public:

private:
	glm::vec3 *m_verticesPos;
	glm::vec3 *m_verticesColor;
	glm::vec3 *m_verticesNor;
	glm::vec2 *m_vecticesTexCoords;
	int m_iNumVerts;
	GLuint m_vertexArrayObj;
	
};

