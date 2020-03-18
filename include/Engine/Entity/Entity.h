#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H


#include <map>

#include "Components/Component.h"
#include "Components/MovementComponent.h"
#include "../renderer/Sprite.h"

namespace Engine {
	namespace Physics {
		class BoxCollider2D;
	}
}

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

			MovementComponent * m_MovComponent;

			bool onGravity = false;
		public:
			Entity();

			virtual ~Entity();

			void AddSprite(Sprite* sprite);
			
			void AddComponent(ComponentType type,Component * component);

			void AddMovementComponent(MovementComponent * component);

			void AddBoxColliderComponent(Physics::BoxCollider2D & body);
			
			void Update(float DeltaTime);

			Sprite * GetSprite();

			
			void OnGravity(bool gravity);
			
			void Move(MovementDirections dir,float velocity,float DeltaTime);
			
			void OnRender(Camera2D & camera);
		};

	}
}



#endif