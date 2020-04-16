#include "../../../include/SandBox/GameObjects/RocketMainCharacter.h"

RocketMainCharacter::RocketMainCharacter(float x,float y)
{
	m_Position = { x,y };
	m_Velocity = { 0.0f,0.0f };

	m_Sprite = GetSprite();


}

void RocketMainCharacter::SetVerticalVelocity(float velocity)
{
	m_Velocity.x = velocity;
}

void RocketMainCharacter::SetHorizontalVelocity(float velocity)
{
	m_Velocity.y = velocity;
}

Engine::Math::Vec2f& RocketMainCharacter::GetVelocity()
{
	return m_Velocity;
}

Engine::Math::Vec2f& RocketMainCharacter::GetPosition()
{
	return m_Position;
}

RocketMainCharacter::~RocketMainCharacter()
{

}
