#include "../../../include/SandBox/GameObjects/GameWorld.h"




GameWorld::GameWorld()
{
	m_Levels.clear();
}

GameWorld::~GameWorld()
{

	for (auto it = m_Levels.begin(); it != m_Levels.end(); it++)
	{
		delete (*it).second;
	}
}
