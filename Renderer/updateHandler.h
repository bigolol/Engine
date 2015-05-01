#pragma once
#include <vector>
#include "UpdateAble.h"
class UpdateHandler
{
public:
	UpdateHandler();
	~UpdateHandler();
	void update(float deltaTime);
	void addUpdateable(Updateable *obj);
private:

public:

private:
	std::vector<Updateable*> m_updateObjVec;
};

