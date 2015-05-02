#pragma once
#include "Listener.h"
class Communicator
{
public:
	Communicator(){};
	virtual ~Communicator(){};
	virtual void notifyAll() = 0;
	virtual void registerMe(Listener *listener) = 0;
};