#pragma once
#include <glm\glm.hpp>
#include <GL\glew.h>
#include <glm\gtc\type_ptr.hpp>
#include "vertex.h"
class Mesh
{
public:
	Mesh(Vertex *vertices, int numVerts);
	~Mesh();
	void initBufferFromData();
	void cleanUp();
	GLuint getVAOHandle() const;
	int getNumVerts() const;
	void bindElementArray(GLushort *element, int numElements);
	int getNumElements();
	Mesh *createPlanarMesh(int width, int height, int numWidthSegs, int numHeightSegs);
private:

public:

private:
	Vertex *m_verts;
	int m_iNumElements;
	int m_iNumVerts;
	
	GLuint m_vertexArrayObj, m_vertexBufferHandle, m_vertexElementHandle;
	
};

