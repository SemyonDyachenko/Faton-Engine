#include  "../../../../include/Engine/Entity/Components/MovementComponent.h"

namespace Engine
{

	MovementComponent::MovementComponent(float maxVelocity, float acceleration) : m_MaxVelocity(maxVelocity), m_Acceleration(acceleration)
	{
		m_Velocity = 0.0f;
	}

	void MovementComponent::OnUpdate(float DeltaTime)
	{
		
	}

	
	void MovementComponent::Destroy()
	{

	}


	

	
}