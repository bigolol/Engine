#pragma once
#include "GraphicsClass.h"
#include <SDL2\SDL.h>
class EngineMain
{
public:
	EngineMain(const int width, const int height, const char const *title);
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

