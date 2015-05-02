#pragma once
#include <SDL2\SDL.h>
#include <GL\glew.h>
#include <iostream>
#include "RenderAble.h"
#include "shaderHandler.h"
#include <vector>
#include "Mesh.h"
#include "GameObject.h"
#include "Camera.h"
#include "ObjectImporter.h"
#include "Listener.h"
class GraphicsClass : public Listener
{
public:
	GraphicsClass(const int width, const int height, const char const *title);
	~GraphicsClass();
	bool setUp();
	void cleanUp();
	void render();
	void getNotified(int x, int y);
	void addRenderable(RenderAble *obj);
	void setCamera(Camera *camera);
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
	Camera *m_pCurrentCamera;
	ObjectImporter m_importer;
	glm::vec3 m_lightSource;
};

