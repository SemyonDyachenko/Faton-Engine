#ifndef ENGINE_GAME_LEVEL_H
#define ENGINE_GAME_LEVEL_H


#include "MainCharacter.h"
#include "RocketMainCharacter.h"

#include "../../../include/Engine/Engine.h"


class MainCharacter;
class RocketMainCharacter;


class GameLevel
{
public:
	GameLevel();

	virtual ~GameLevel();

	void OnUpdate(float DeltaTime);

	void OnRender();

	bool IsOver();

protected:

private:
	bool m_Over;

	Engine::Entity::Scene2D* m_Scene;

	MainCharacter* m_MainCharacter;
	RocketMainCharacter* m_RocketMainCharacter;

	
};



#endif