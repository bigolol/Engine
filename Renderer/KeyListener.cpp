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

	if (m_bIsPressed[SDL_SCANCODE_W])
		m_camera->performAction(MOVE_FORWARD);
	if (m_bIsPressed[SDL_SCANCODE_S])
		m_camera->performAction(MOVE_BACKWARDS);
	if (m_bIsPressed[SDL_SCANCODE_D])
		m_camera->performAction(MOVE_RIGHT);
	if (m_bIsPressed[SDL_SCANCODE_A])
		m_camera->performAction(MOVE_LEFT);
	if (m_bIsPressed[SDL_SCANCODE_SPACE])
		m_camera->performAction(JUMP);
}