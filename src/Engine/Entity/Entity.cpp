#include "..\..\..\include\Engine\Entity\Entity.h"


namespace Engine
{


	namespace Entity
	{
		Entity::Entity()
		{

			m_Sprite = nullptr;
			m_MovComponent = nullptr;
			
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

		void Entity::AddMovementComponent(MovementComponent* component)
		{
			m_MovComponent = component;
		}

		void Entity::AddBoxColliderComponent(Physics::BoxCollider2D& body)
		{
			m_BoxCollider =&body;
		}

		void Entity::Update(float DeltaTime)
		{
			if(m_Sprite != nullptr && this->m_MovComponent)
			{
				
			}

			if(m_Sprite != nullptr && this->onGravity)
			{
				m_Sprite->MoveDown(DeltaTime,0.98);
			}
		}

		Sprite* Entity::GetSprite()
		{
			if (m_Sprite != nullptr)
			{
				return m_Sprite;
			}
			else
			{
				return nullptr;
			}
		}

		void Entity::OnGravity(bool gravity)
		{
		}

		void Entity::Move(MovementDirections dir, float velocity, float DeltaTime)
		{
			if (m_Sprite != nullptr && this->m_MovComponent)
			{
				if(dir == MovementDirections::UP)
				{
					m_Sprite->MoveUp(DeltaTime, velocity);
				}
				else if(dir == MovementDirections::DOWN)
				{
					m_Sprite->MoveDown(DeltaTime, velocity);
				}
				else if(dir == MovementDirections::LEFT)
				{
					m_Sprite->MoveLeft(DeltaTime, velocity);
				}
				else if(dir == MovementDirections::RIGHT)
				{
					m_Sprite->MoveRight(DeltaTime, velocity);
				}
			}
		}

		void Entity::OnRender(Camera2D& camera)
		{
			if(m_Sprite != nullptr)
			{
				m_Sprite->OnRender(camera);
			}
		}
	}

}