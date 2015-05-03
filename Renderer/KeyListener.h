#pragma once
#include "Camera.h"
#include "SDL2\SDL.h"
#include "commandable.h"
class KeyListener
{
public:
	KeyListener(Camera *camera);
	~KeyListener();
	void listenForKeys();
private:
	Camera *m_camera;
	const Uint8 *m_bIsPressed;
};

