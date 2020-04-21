#ifndef ENGINE_GAME_ENTITY_H
#define ENGINE_GAME_ENTITY_H


#include "../../Engine/Engine.h"

class GameEntity
{
public:
	GameEntity();

	virtual ~GameEntity();

	virtual void Update(float DeltaTime) = 0;

	virtual void Render(Engine::Camera2D& camera) = 0;
protected:
private:

};

#endif