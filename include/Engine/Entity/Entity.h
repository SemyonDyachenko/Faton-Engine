#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H


#include <map>

#include "Components/Component.h"
#include "Components/MovementComponent.h"
#include "../renderer/Sprite.h"

namespace Engine
{
	namespace Entity
	{
		
		class Entity
		{
		protected:
			std::map<ComponentType,Component*> m_Components;

			Sprite * m_Sprite;

			MovementComponent * m_MovComponent;
		public:
			Entity();

			virtual ~Entity();

			void AddSprite(Sprite* sprite);
			
			void AddComponent(ComponentType type,Component * component);

			void AddMovementComponent(MovementComponent * component);

			void Update(float DeltaTime);
		};

	}
}



#endif