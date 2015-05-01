#pragma once
#include <glm\glm.hpp>
class Vertex
{
public:
	Vertex();

	Vertex(glm::vec3 position);

	~Vertex();
	void init();
	void cleanUp();

	void addPosData(glm::vec3 posData);
	void addNormalData(glm::vec3 normData);
	void addColorData(glm::vec3 colData);
	void addTexData(glm::vec2 texData);

	glm::vec3 getPos();
	glm::vec3 getNorm();
	glm::vec3 getCol();
	glm::vec2 getTexCoords();

private:

public:

private:
	glm::vec3 m_position;
	glm::vec3 m_color;
	glm::vec3 m_normal;
	glm::vec2 m_texCoord;
};

