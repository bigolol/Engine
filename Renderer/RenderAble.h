#pragma once

#include "Camera.h"
class RenderAble
{
public:
	RenderAble();
	~RenderAble();
	virtual void render(Camera *camera) = 0;
	virtual void cleanUp() = 0;
private:

public:

private:


};

