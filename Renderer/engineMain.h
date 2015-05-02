#pragma once
#include "GraphicsClass.h"
#include <SDL2\SDL.h>
#include "updateHandler.h"
#include "GameObject.h"
#include "Mesh.h"
#include "ObjectImporter.h"
#include "shaderHandler.h"
#include "MouseListener.h"
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
	UpdateHandler m_updater;
	ObjectImporter m_importer;
	ShaderHandler m_handler;
	MouseListener m_mouseListener;
};

