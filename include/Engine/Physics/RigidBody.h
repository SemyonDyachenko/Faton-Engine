#ifndef ENGINE_RIGIDBODY_H
#define ENGINE_RIGIDBODY_H
#include "../Math/Math.h"
#include "../Core/Core.h"



namespace  Engine
{
	namespace Physics
	{
		enum ForceMode
		{
			Impulse,
			Force,
			Acceleration,
			VelocityChange
		};
		
		enum RigidBodyType
		{
			rd_staticBody = 0,
			rd_kinematicBody,
			rd_dynamicBody
		};

		
		class RigidBody
		{
		public:
			
			RigidBody(RigidBodyType type);
			virtual ~RigidBody();

			void OnUpdate(float DeltaTime);

			void Enable();
			void Disable();
			bool IsEnabled();
			
			
			void AddForce(Math::Vec2f force,ForceMode mode = ForceMode::Force);
			void AddForce(float x, float y,ForceMode = ForceMode::Force);

		
			void AddRelativeForce(Math::Vec2f force, ForceMode = ForceMode::Force);
			
			void AddTorque(Math::Vec2f torque,ForceMode = ForceMode::Force);
			void PointVelocity();
			bool IsSleeping();
			void MovePosition(Math::Vec2f position);
			void MoveRotation(float rotationAngle);
			void Sleep();
			void WakeUp();

			void SetPosition(Math::Vec2f position);
			void SetPosition(float x, float y);
			void SetRotation(float angle);

			void SetType(RigidBodyType type);

			RigidBodyType GetType() const;

			Math::Vec2f& GetPosition();
			float GetRotation() const;

			float GetMass() const;
			void SetMass(float mass);

			void AddAngularImpulse(float impulse, bool wake);
			void AddLinearImpulse(const Math::Vec2f impulse, const Math::Vec2f point, bool wake);

			void SetSleepTime(float time);
			
			void Destroy();
		private:
			
			
			RigidBodyType type;

			Math::Vec2f position;
			Math::Vec2f linearVelocity;
			Math::Vec2f angularVelocity;

			bool Enabled;
			bool FixedRotation;

			float mass;

			bool sleep;
			
			float SleepTime;

			Math::Vec2f force;
			Math::Vec2f torque;

			
			float Angle;
			float Rotation;
			Math::Vec2f Velocity;
			
		};
		
	}
}



#endif