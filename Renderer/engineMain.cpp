#include "engineMain.h"


EngineMain::EngineMain(int width, int height, char *title) : m_iHeight(height), m_iWidth(width), m_sTitle(title)
{
}


EngineMain::~EngineMain()
{
}

void EngineMain::init()
{
	m_window = SDL_CreateWindow(m_sTitle, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, m_iWidth, m_iHeight, SDL_WINDOW_OPENGL;
}

void EngineMain::cleanUp()
{
	SDL_DestroyWindow(m_window);
}