#ifndef GAME_ROCKET_MAIN_CHARACTER_H
#define GAME_ROCKET_MAIN_CHARACTER_H

#include "../../../include/Engine/Engine.h"

enum MovementEvents
{
	FLY_RIGHT,
	FLY_TOP,
	FLY_BOTTOM,
	FIRE,
	ACCELERATION,
};



class RocketMainCharacter : public Engine::Entity::Entity
{
public:
	RocketMainCharacter(float x,float y);


	void SetVerticalVelocity(float velocity);
	void SetHorizontalVelocity(float velocity);


	Engine::Math::Vec2f& GetVelocity();
	Engine::Math::Vec2f& GetPosition();

	virtual ~RocketMainCharacter();

private:
	MovementEvents event;

	Engine::Math::Vec2f m_Velocity;
	Engine::Math::Vec2f m_Position;
	

	float m_Gravity = 0.0f;

	std::map<std::string, Engine::Animation*> m_Animation;
};


#endif