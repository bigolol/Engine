#pragma once
#include "Listener.h"
#include <SDL2\SDL.h>
#include <vector>
#include "Communitactor.h"
class MouseListener : public Communicator
{
public:
	MouseListener();
	virtual ~MouseListener();
	void registerMe(Listener *listener);
	void checkMouse();
	void notifyAll();
private:
	
public:

private:
	std::vector<Listener*> m_listenerVec;
	int m_iX;
	int m_iY;
};

