#pragma once
#include "GraphicsClass.h"
#include <SDL2\SDL.h>
class EngineMain
{
public:
	EngineMain();
	~EngineMain();
	void init(int width, int height, char *title);
	void cleanUp();
private:
	EngineMain operator=(const EngineMain& rhs);
	EngineMain(const EngineMain& rhs);

public:

private:
	GraphicsClass m_graphics;
};

