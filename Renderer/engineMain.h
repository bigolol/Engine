#pragma once
#include "GraphicsClass.h"
#include <SDL2\SDL.h>
class EngineMain
{
public:
	EngineMain(int width, int height, char *title);
	~EngineMain();
	void init();
	void cleanUp();
private:
	EngineMain operator=(const EngineMain& rhs);
	EngineMain(const EngineMain& rhs);

	void mainLoop();

public:

private:
	GraphicsClass m_graphics;
};

