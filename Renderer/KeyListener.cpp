#include "KeyListener.h"


KeyListener::KeyListener(Camera *camera) : m_camera(camera)
{
}


KeyListener::~KeyListener()
{
}

void KeyListener::listenForKeys()
{
	m_bIsPressed = SDL_GetKeyboardState(NULL);
	bool scanCodes[] = {
		m_bIsPressed[SDL_SCANCODE_W],
		m_bIsPressed[SDL_SCANCODE_S],
		m_bIsPressed[SDL_SCANCODE_D],
		m_bIsPressed[SDL_SCANCODE_A],
	};
	m_camera->move(scanCodes, .3);
}