#ifndef ENGINE_MOVEMENT_COMPONENT_H
#define ENGINE_MOVEMENT_COMPONENT_H

#include "Component.h"

namespace Engine
{

	class MovementComponent : public Component
	{
	public:
		MovementComponent(float maxVelocity,float acceleration);

		void OnUpdate(float DeltaTime) override;

		void Destroy() override;

	public:
		float m_Velocity;
		float m_Acceleration;
		float m_MaxVelocity;
	};

}



#endif 