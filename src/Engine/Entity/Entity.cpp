#include "..\..\..\include\Engine\Entity\Entity.h"


namespace Engine
{


	namespace Entity
	{
		Entity::Entity()
		{

			m_Sprite = nullptr;
			
			if(m_Sprite != nullptr)
			{
			
			}
		}

		Entity::~Entity()
		{
		}

		void Entity::AddSprite(Sprite* sprite)
		{
			m_Sprite = sprite;
		}

		void Entity::AddComponent(ComponentType type,Component * component)
		{
			m_Components[type] = component;
		}


	}

}