#pragma once
#include "RenderAble.h"
#include "vertex.h"
#include <iostream>
#include <GL\glew.h>
#include <glm\gtc\type_ptr.hpp>
#include "Mesh.h"
class Terrain :
	public RenderAble
{
public:
	Terrain(GLuint program, Mesh *mesh);
	virtual ~Terrain();
	void render(Camera *camera, glm::vec3 lightSource);
	void cleanUp();
	void createTerrain();
	void createPlane(int x, int z, int xSegmentNum, int zSegmentNum);
private:
	Vertex *m_terrainData;
	GLuint m_program;
	GLuint m_vertaxArrayBuffer;
	Mesh *m_mesh;
};

