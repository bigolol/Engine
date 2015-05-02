#pragma once
#include "Listener.h"
#include <SDL2\SDL.h>
#include <vector>
class MouseListener
{
public:
	MouseListener();
	virtual ~MouseListener();
	void registerMe(Listener *listener);
	void checkMouse();
	void notifyAll();
	int getX() const;
	int getY() const;
private:
	
public:

private:
	std::vector<Listener*> m_listenerVec;
	int m_iX;
	int m_iY;
};

