#pragma once

#include "Camera.h"
#include <glm\glm.hpp>
class RenderAble
{
public:
	RenderAble(){};
	virtual ~RenderAble(){};
	virtual void render(Camera *camera, glm::vec3 lightSource) = 0;
	virtual void cleanUp() = 0;
private:
public:

private:


};

