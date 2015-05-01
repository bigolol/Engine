#include "vertex.h"


Vertex::Vertex()
{
}

Vertex::Vertex(glm::vec3 position) : m_position(position)
{
}


Vertex::~Vertex()
{
}

void Vertex::addPosData(glm::vec3 posData)
{
	m_position = posData;
}
void Vertex::addNormalData(glm::vec3 normData)
{
	m_normal = normData;
}
void Vertex::addColorData(glm::vec3 colData)
{
	m_color = colData;
}
void Vertex::addTexData(glm::vec2 texData)
{
	m_texCoord = texData;
}


glm::vec3 Vertex::getPos()
{
	return m_position;
}
glm::vec3 Vertex::getNorm()
{
	return m_normal;
}
glm::vec3 Vertex::getCol()
{
	return m_color;
}
glm::vec2 Vertex::getTexCoords()
{
	return m_texCoord;
}