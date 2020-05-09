#ifndef GAME_ASTEROID_OBJECT_H
#define GAME_ASTEROID_OBJECT_H


#include "../GameEntity.h"


class Asteroid : public GameEntity, public Engine::Entity::Entity
{
public:
	Asteroid(float rotation,float x,float y, Engine::Math::Vec2f velocity);

	~Asteroid();

	void Update(float DeltaTime) override;

	const bool& IsDestroyed();

	void Render(Engine::Camera2D& camera) override;

	void Destroy();

	void Start();


private:
	Engine::Math::Vec2f m_Position;
	Engine::Math::Vec2f m_Velocity;

	bool Started = false;
	bool Destroyed = false;

	float m_Rotation;


};


#endif