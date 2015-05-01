#pragma once
#include <SDL2\SDL.h>
#include <GL\glew.h>
#include <iostream>
#include "RenderAble.h"
#include "shaderHandler.h"
#include <vector>
#include "Mesh.h"
#include "GameObject.h"
class GraphicsClass
{
public:
	GraphicsClass(const int width, const int height, const char const *title);
	~GraphicsClass();
	bool setUp();
	void cleanUp();
	void render();
	void addRenderable(RenderAble *obj);
private:
	
public:

private:
	int m_iWidth;
	int m_iHeight;
	const char *m_cTitle;
	SDL_Window *m_pWindow;
	SDL_GLContext m_context;
	ShaderHandler m_shaderHandler;
	std::vector<RenderAble*> m_renderVector;
};

