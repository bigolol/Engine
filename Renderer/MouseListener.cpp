#include "MouseListener.h"


MouseListener::MouseListener()
{
	SDL_GetMouseState(&m_iX, &m_iY);
	m_iX -= 400;
	m_iY -= 300;
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
	newX -= 400;
	newY -= 300;
	if (newX != m_iX || newY != m_iY)
	{
		m_iX = newX;
		m_iY = newY;
		notifyAll();
	}
}

int MouseListener::getX() const
{
	return m_iX;
}
int MouseListener::getY() const
{
	return m_iY;
}

void MouseListener::notifyAll()
{
	for (int i = 0; i < m_listenerVec.size(); ++i)
	{
		m_listenerVec[i]->getNotified(m_iX, m_iY);
	}
}