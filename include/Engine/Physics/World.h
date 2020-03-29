#ifndef ENGINE_PHYSICS_WORLD_H
#define ENGINE_PHYSICS_WORLD_H
#include <vector>

#include "../Math/Math.h"
#include "RigidBody.h"


namespace Engine
{
	namespace Physics
	{


		class World
		{
		public:
			World(Math::Vec2f & gravity);

			virtual ~World();

			RigidBody * createBody(RigidBodyType type);

			void DestroyRigidBody(RigidBody * body);

			void ClearForces();

			int GetBodyCount() const;

			void SetGravity(Math::Vec2f & gravity);
		private:
			friend RigidBody;

			Math::Vec2f m_Gravity;
			std::vector<RigidBody> m_BodyList;
		};
		
	}
}


#endif