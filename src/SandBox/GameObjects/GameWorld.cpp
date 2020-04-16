#include "../../../include/SandBox/GameObjects/GameWorld.h"




GameWorld::GameWorld()
{
	m_Levels.clear();

	m_Levels[m_CurrentLevelName] = new GameLevel();
}

void GameWorld::SetCurrentLevel(std::string& levelName)
{
	this->m_CurrentLevelName = levelName;
}

GameLevel* GameWorld::GetCurrentLevel()
{
	return nullptr;
}

void GameWorld::AddLevel(std::string& levelName, GameLevel* level)
{
	m_Levels[levelName] = level;
}

GameWorld::~GameWorld()
{

	for (auto it = m_Levels.begin(); it != m_Levels.end(); it++)
	{
		delete (*it).second;
	}
}

void GameWorld::Update(float DeltaTime)
{
	if (!m_Levels[m_CurrentLevelName]->IsOver())
	{
		if (!m_Levels[m_CurrentLevelName]->IsLoaded())
		{
			m_Levels[m_CurrentLevelName]->OnUpdate(DeltaTime);
		}
	}
}

void GameWorld::Render()
{
	m_Levels[m_CurrentLevelName]->PreLoadingRender();

	if(!m_Levels[m_CurrentLevelName]->IsOver())
	{
		if (!m_Levels[m_CurrentLevelName]->IsLoaded())
		{
			m_Levels[m_CurrentLevelName]->OnRender();
		}
	}
}
