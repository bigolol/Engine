#pragma once
#include "Listener.h"
#include <vector>
class KeyListener
{
public:
	KeyListener();
	~KeyListener();
	void registerMe(Listener *listener);
	virtual void notifyAll();

private:
	std::vector<Listener *> m_listenerVector;
};

