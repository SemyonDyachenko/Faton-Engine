#ifndef GAME_LEVEL_POINT_H
#define GAME_LEVEL_POINT_H

#include "../../../include/Engine/Engine.h"

class LevelPoint : public Engine::Entity::Entity
{
public:
	LevelPoint();

	virtual ~LevelPoint();

	void Update();

	void Render();
private:
	Engine::Math::Vec2f m_Position;

};



#endif