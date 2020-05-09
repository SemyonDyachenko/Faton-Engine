#include "../../../../include/SandBox/GameObjects/GameEntities/Asteroid.h"



Asteroid::Asteroid(float rotation,float x, float y, Engine::Math::Vec2f velocity)
{
	m_Position = { x,y };
	m_Velocity = velocity;
}

Asteroid::~Asteroid()
{

}

void Asteroid::Update(float DeltaTime)
{
	//if (Started && !Destroyed)
	//{
		m_Position.x += m_Velocity.x * DeltaTime;
		m_Position.y += m_Velocity.y * DeltaTime;
		Move(m_Velocity.x, m_Velocity.y,DeltaTime);
	//}
}

const bool& Asteroid::IsDestroyed()
{
	return Destroyed;
}


void Asteroid::Render(Engine::Camera2D& camera)
{
}

void Asteroid::Destroy()
{
	Destroyed = true;
}

void Asteroid::Start()
{
	Started = true;
}
