#pragma once

class Updateable
{
public:
	Updateable(){};
	virtual ~Updateable(){};
	virtual void update(float deltaTime) = 0;
private:
};