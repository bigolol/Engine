#pragma once

class Listener
{
public:
	Listener(){};
	virtual ~Listener(){};
	virtual void getNotified(int x, int y) = 0;
};