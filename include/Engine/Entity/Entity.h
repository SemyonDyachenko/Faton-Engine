#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H


#include <map>

#include "Components/Component.h"
#include "Components/MovementComponent.h"
#include "../renderer/Sprite.h"
#include "../../../include/Engine/Physics/BoxCollider2D.h"
#include "../Physics/RigidBody.h"


namespace Engine
{
	namespace Entity
	{
		enum MovementDirections
		{
			LEFT,
			RIGHT,
			UP,
			DOWN
		};
		
		class Entity
		{
		protected:
		
			
			std::map<ComponentType,Component*> m_Components;

			Sprite * m_Sprite;

			Physics::BoxCollider2D * m_BoxCollider;

			Physics::RigidBody * m_rigidBody;
			
			MovementComponent * m_MovComponent;

			bool onGravity = false;
		public:
			Entity();

			virtual ~Entity();

			void AddSprite(Sprite* sprite);
			
			void AddComponent(ComponentType type,Component * component);

			void AddRigidBodyComponent(Physics::RigidBody * body);
			void AddMovementComponent(MovementComponent * component);

			void AddBoxColliderComponent();

			Physics::BoxCollider2D& GetCollider2D() const;

			Physics::RigidBody& GetRigidBody() const;
			
			void Update(float DeltaTime);

			MovementComponent& GetMovementComponent() const;

			Sprite * GetSprite() const;

			
			void OnGravity(bool gravity);
			
			void Move(float x,float y,float DeltaTime);
			
			void OnRender(Camera2D & camera);
		};

	}
}



#endif