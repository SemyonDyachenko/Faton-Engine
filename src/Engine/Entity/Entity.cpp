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

		void Entity::AddBoxColliderComponent()
		{
			if(m_Sprite != nullptr)
				m_BoxCollider = new Physics::BoxCollider2D(m_Sprite->GetBounds());
		}

		Physics::BoxCollider2D& Entity::GetCollider2D() const
		{
			if (m_BoxCollider != nullptr)
			{
				return *m_BoxCollider;
			}
			
		}

		void Entity::Update(float DeltaTime)
		{
			if(m_Sprite != nullptr && this->m_MovComponent)
			{
				
			}

			
		}

		MovementComponent& Entity::GetMovementComponent() const
		{
			return *m_MovComponent;
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
			onGravity = gravity;
		}

		void Entity::Move(float x, float y, float DeltaTime)
		{
			if (m_Sprite != nullptr && this->m_MovComponent)
			{
				this->m_MovComponent->Move(x, y, DeltaTime);
				this->m_Sprite->Move(m_MovComponent->GetVelocity().x, m_MovComponent->GetVelocity().y);
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
