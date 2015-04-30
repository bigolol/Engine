#pragma once
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

public:

private:
	int m_iWidth;
	int m_iHeight;
	const char *m_sTitle;
	SDL_Window *m_window;
};

