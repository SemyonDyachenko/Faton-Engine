#ifndef ENGINE_GAME_LEVEL_H
#define ENGINE_GAME_LEVEL_H


#include "MainCharacter.h"
#include "RocketMainCharacter.h"

#include "../../../include/Engine/Engine.h"
#include "GameEntity.h"


class MainCharacter;
class RocketMainCharacter;


class GameLevel
{
public:
	GameLevel();

	virtual ~GameLevel();

	void OnUpdate(float DeltaTime);

	bool IsLoaded();

	void PreLoadingRender();

	void OnRender();

	bool IsOver();

protected:

private:
	bool m_Over;
	bool m_Loading;

	Engine::Entity::Scene2D* m_Scene;


	std::vector<GameEntity*> m_Entities;

	MainCharacter* m_MainCharacter;

	
};



#endif