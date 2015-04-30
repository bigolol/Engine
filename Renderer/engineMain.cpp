#include "engineMain.h"


EngineMain::EngineMain() 
{
}


EngineMain::~EngineMain()
{
}

void EngineMain::init(int width, int height, char *title)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	m_graphics = GraphicsClass(width, height, title);
	if (!m_graphics.setUp())
	{
		cleanUp();
	}
}

void EngineMain::cleanUp()
{
	m_graphics.cleanUp();
	SDL_Quit();
}