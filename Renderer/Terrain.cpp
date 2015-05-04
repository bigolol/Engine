#include "Terrain.h"


Terrain::Terrain(GLuint program, Mesh *mesh)
{
	m_program = program;
	m_mesh = mesh;
}


Terrain::~Terrain()
{
}


void Terrain::createTerrain()
{
	m_terrainData = new Vertex[20 * 20];
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			m_terrainData[i * 20 + j] = Vertex(glm::vec3(i - 10, -4.0f, j - 10));
			m_terrainData[i * 20 + j].addColorData(glm::vec3(.5f, .5f, .5f));
		}
	}
	glGenVertexArrays(1, &m_vertaxArrayBuffer);
	GLuint vertexBufferHandle;
	glGenBuffers(1, &vertexBufferHandle);
	glBindVertexArray(m_vertaxArrayBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);

	glBufferData(vertexBufferHandle, sizeof(m_terrainData[0]) * 20 * 20, m_terrainData, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(m_terrainData[0]), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(m_terrainData[0]), (GLvoid*)sizeof(glm::vec3));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void Terrain::cleanUp()
{

}

void Terrain::render(Camera *camera, glm::vec3 lightSource)
{
	glUseProgram(m_program);

	GLint matLoc = glGetUniformLocation(m_program, "projViewMat");
	glUniformMatrix4fv(matLoc, 1, GL_FALSE, glm::value_ptr(camera->getViewAndProjMatrix()));

	GLint lightLoc = glGetUniformLocation(m_program, "lightSource");
	glUniform3fv(lightLoc, 1, glm::value_ptr(lightSource));

	glBindVertexArray(m_mesh->getVAOHandle());
	glDrawArrays(GL_TRIANGLES, 0, m_mesh->getNumElements());
	glBindVertexArray(0);

	glUseProgram(0);
}

void Terrain::createPlane(int x, int z, int xSegmentNum, int zSegmentNum)
{
	int xStepLength = x / xSegmentNum;
	int zStepLength = z / zSegmentNum;

	for (int i = 0; i < xSegmentNum; ++i)
	{
		for (int z = 0; z < zSegmentNum; ++z)
		{

		}
	}
}