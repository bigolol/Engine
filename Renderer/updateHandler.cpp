#include "updateHandler.h"


UpdateHandler::UpdateHandler()
{
}


UpdateHandler::~UpdateHandler()
{
}


void UpdateHandler::update(float deltaTime)
{
	for (int i = 0; i < m_updateObjVec.size(); ++i)
	{
		m_updateObjVec[i]->update(deltaTime);
	}
}
void UpdateHandler::addUpdateable(Updateable *obj)
{
	m_updateObjVec.push_back(obj);
}
