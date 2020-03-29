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

			this->SleepTime = 0.0f;
			this->FixedRotation = 0.0f;
			this->Angle = 0.0f;
			this->Rotation = 0.0f;
		}

		RigidBody::~RigidBody()
		{
		}

		void RigidBody::OnUpdate(float DeltaTime)
		{
			this->position.x += force.x;
			this->position.y += force.y;
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
			this->position.x += position.x;
			this->position.y += position.y;
		}

		void RigidBody::MoveRotation(float rotationAngle)
		{
			this->Rotation = rotationAngle;
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

		void RigidBody::SetPosition(Math::Vec2f position)
		{
			this->position = position;
		}

		void RigidBody::SetPosition(float x, float y)
		{
			this->position.x = x;
			this->position.y = y;
		}

		void RigidBody::SetRotation(float angle)
		{
			this->Rotation = angle;
		}

		void RigidBody::SetType(RigidBodyType type)
		{
			this->type = type;
		}

		RigidBodyType RigidBody::GetType() const
		{
			return this->type;
		}

		float RigidBody::GetMass() const
		{
			if(this->type == RigidBodyType::rd_dynamicBody)
			{
				return mass;
			}
			else
			{
				return 0.0f;
			}
		}
		

		void RigidBody::SetMass(float mass)
		{
			if(this->type == RigidBodyType::rd_dynamicBody)
			{
				this->mass = mass;
			}
			else
			{
				FATON_ERROR_03;
			}
		}

		void RigidBody::AddAngularImpulse(float impulse, bool wake)
		{
			
		}

		void RigidBody::AddLinearImpulse(const Math::Vec2f impulse, const Math::Vec2f point, bool wake)
		{
			
		}

		void RigidBody::SetSleepTime(float time)
		{
			this->SleepTime = time;
		}

		void RigidBody::Destroy()
		{
			this->mass = 0.0f;
			this->force = { 0.0f,0.0f };
			this->torque = { 0.0f,0.0f };
			this->Rotation = 0.0f;
			this->SleepTime = 0.0f;
		}
	}
}
