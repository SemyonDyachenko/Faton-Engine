#ifndef ENGINE_MOVEMENT_COMPONENT_H
#define ENGINE_MOVEMENT_COMPONENT_H

#include "Component.h"
#include "../../Math/Vector2.hpp"
#include "../../renderer/Sprite.h"

namespace Engine
{

	enum MovementStates
	{
		IDLE = 0,
		MOVING,
		MOVE_LEFT,
		MOVE_RIGHT,
		MOVE_JUMP
	};
	
	class MovementComponent : public Component
	{
	public:
		MovementComponent(Sprite& sprite,float maxVelocity,float acceleration);

		void OnUpdate(float DeltaTime) override;

		const float& GetMaxVelocity() const;
		const Math::Vec2f& GetVelocity() const;

		void Move(const float x, const float y, float DeltaTime);
		
		void StopVelocityX();
		void StopVelocityY();
		
		const bool GetState(const short unsigned state);
		

		void Destroy() override;

	private:
		float m_Acceleration;
		float m_Decceleration;
		float m_MaxVelocity;

		Math::Vec2f m_Velocity;
	};

}



#endif 