#include "../../../include/SandBox/GameObjects/GameLevel.h"

GameLevel::GameLevel()
{
	m_Loading = true;
}

GameLevel::~GameLevel()
{
}

void GameLevel::OnUpdate(float DeltaTime)
{
}

bool GameLevel::IsLoaded()
{
	return m_Loading;
}

void GameLevel::PreLoadingRender()
{

}

void GameLevel::OnRender()
{
}

bool GameLevel::IsOver()
{
	return false;
}
