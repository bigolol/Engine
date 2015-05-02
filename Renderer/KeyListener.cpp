#include "KeyListener.h"


KeyListener::KeyListener()
{
}


KeyListener::~KeyListener()
{
}

void KeyListener::registerMe(Listener *listener)
{
	m_listenerVector.push_back(listener);
}

void KeyListener::notifyAll()
{
	for (int i = 0; i < m_listenerVector.size(); ++i)
	{
		m_listenerVector[i]->getNotified(1, 1);
	}
}