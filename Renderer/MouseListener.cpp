#include "MouseListener.h"


MouseListener::MouseListener()
{
}


MouseListener::~MouseListener()
{
}

void MouseListener::registerMe(Listener *listener)
{
	m_listenerVec.push_back(listener);
}

void MouseListener::checkMouse()
{
	int newX, newY;
	SDL_GetMouseState(&newX, &newY);
	//transform so that 0 0 is in the middle of the screen
	newX -= 400;
	newY -= 300;
	if (newX != m_iX || newY != m_iY)
	{
		m_iX = newX;
		m_iY = newY;
		notifyAll();
	}
}

void MouseListener::notifyAll()
{
	for (int i = 0; i < m_listenerVec.size(); ++i)
	{
		m_listenerVec[i]->getNotified(m_iX, m_iY);
	}
}