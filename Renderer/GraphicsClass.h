#pragma once
#include <SDL2\SDL.h>
#include <GL\glew.h>
#include <iostream>

#include "shaderHandler.h"
class GraphicsClass
{
public:
	GraphicsClass(int width, int height, char *title);
	~GraphicsClass();
	bool setUp();
	void cleanUp();
	void render();
private:
	
public:

private:
	int m_iWidth;
	int m_iHeight;
	const char *m_cTitle;
	SDL_Window *m_pWindow;
	SDL_GLContext m_context;

	ShaderHandler m_shaderHandler;
};

