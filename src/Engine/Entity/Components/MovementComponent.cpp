#include  "../../../../include/Engine/Entity/Components/MovementComponent.h"

namespace Engine
{


	MovementComponent::MovementComponent(Sprite& sprite, float maxVelocity, float acceleration) : m_MaxVelocity(maxVelocity), m_Acceleration(acceleration)
	{
		m_Velocity = { 0.0f,0.0f };
	}

	void MovementComponent::OnUpdate(float DeltaTime)
	{
		while(m_Velocity.x <= m_MaxVelocity)
		{
			m_Velocity.x += m_Acceleration * DeltaTime;
			
		}
	}

	const float& MovementComponent::GetMaxVelocity() const
	{
		return m_MaxVelocity;
	}

	const Math::Vec2f& MovementComponent::GetVelocity() const
	{
		return m_Velocity;
	}

	void MovementComponent::Move(const float x, const float y, float DeltaTime)
	{
		
			this->m_Velocity.x =  x;
			this->m_Velocity.y =  y;
		
	}


	void MovementComponent::StopVelocityX()
	{
		this->m_Velocity.x = 0.0f;
	}

	void MovementComponent::StopVelocityY()
	{
		this->m_Velocity.y = 0.0f;
	}


	const bool MovementComponent::GetState(const unsigned short state)
	{
		return false;
	}


	void MovementComponent::Destroy()
	{
		m_Acceleration = 0.0f;
		m_Velocity = { 0.0f,0.0f };
		m_Decceleration = 0.0f;
		m_MaxVelocity = 0.0f;
	}


	

	
}