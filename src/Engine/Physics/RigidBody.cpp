#include "../../../include/Engine/Physics/RigidBody.h"


namespace Engine
{
	namespace  Physics
	{
		RigidBody::RigidBody(RigidBodyType type)
		{
			
			this->type = type;

			if(this->type == RigidBodyType::rd_kinematicBody)
			{
				this->mass = 0.0f;
			}
			
			this->Enabled = false;
			this->sleep = false;
		}

		RigidBody::~RigidBody()
		{
		}

		void RigidBody::Enable()
		{
			this->Enabled = true;
		}

		void RigidBody::Disable()
		{
			this->Enabled = false;
		}

		bool RigidBody::IsEnabled()
		{
			return this->Enabled;
		}

		void RigidBody::AddForce(Math::Vec2f force, ForceMode mode)
		{
			this->force = force;
		}

		void RigidBody::AddForce(float x, float y, ForceMode)
		{
			this->force.x = x;
			this->force.y = y;

			position.x += force.x;
			position.y += force.y;
		}

		void RigidBody::AddRelativeForce(Math::Vec2f force, ForceMode)
		{
		}

		void RigidBody::AddTorque(Math::Vec2f torque, ForceMode)
		{
			this->torque = torque;
		}



		void RigidBody::PointVelocity()
		{
		}

		bool RigidBody::IsSleeping()
		{
			return sleep;
		}

		void RigidBody::MovePosition(Math::Vec2f position)
		{
			this->position = position;
		}

		void RigidBody::MoveRotation()
		{
		}

		void RigidBody::Sleep()
		{
			if (!sleep)
				sleep = true;
		}

		void RigidBody::WakeUp()
		{
			if (sleep)
				sleep = false;
		}

		void RigidBody::Destroy()
		{
		}
	}
}
