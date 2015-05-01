#include "engineMain.h"


EngineMain::EngineMain(const int width, const int height, const char const *title) : m_graphics(width, height, title)
{

}


EngineMain::~EngineMain()
{
}

void EngineMain::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	if (!m_graphics.setUp())
	{
		cleanUp();
	}
	
	
	mainLoop();
}

void EngineMain::cleanUp()
{
	m_graphics.cleanUp();
	SDL_Quit();
}


void EngineMain::mainLoop()
{
	bool running = true;
	SDL_Event event;
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}
		m_graphics.render();
	}
	cleanUp();
}