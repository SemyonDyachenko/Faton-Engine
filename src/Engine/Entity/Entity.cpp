#include "..\..\..\include\Engine\Entity\Entity.h"




namespace Engine
{


	namespace Entity
	{
		Entity::Entity()
		{

			m_Sprite = nullptr;
			m_MovComponent = nullptr;
			m_rigidBody = nullptr;
			m_BoxCollider = nullptr;
			m_AnimationComponent = nullptr;

			if(m_Sprite != nullptr)
			{
				
			}
		}

		Entity::~Entity()
		{
		}

		void Entity::AddSpriteComponent(Sprite* sprite)
		{
			m_Sprite = sprite;
		}

		void Entity::AddComponent(ComponentType type,Component * component)
		{
			m_Components[type] = component;
		}

		void Entity::AddRigidBodyComponent(Physics::RigidBody* body)
		{
			m_rigidBody = body;
		}

		void Entity::AddMovementComponent(MovementComponent* component)
		{
			m_MovComponent = component;
		}

		void Entity::AddAnimationCompoment(AnimationComponent* component)
		{
			m_AnimationComponent = component;
		}

		

		void Entity::AddBoxColliderComponent()
		{
			if(m_Sprite != nullptr)
				m_BoxCollider = new Physics::BoxCollider2D(m_Sprite->GetBounds());
		}

		Physics::BoxCollider2D& Entity::GetCollider2D() const
		{
			return *m_BoxCollider;
		}

		Physics::RigidBody& Entity::GetRigidBody() const
		{
			return *m_rigidBody;
		}

		void Entity::OnUpdate(float DeltaTime)
		{
			if(m_Sprite != nullptr && this->m_MovComponent)
			{
				
			}

			if(m_MovComponent)
			{
				m_MovComponent->OnUpdate(DeltaTime);
			}

			if (onGravity)
			{
				Move(0.0f, -0.098f, DeltaTime);
			}
			

			if(m_rigidBody)
			{
				m_Sprite->SetPosition(m_rigidBody->GetPosition());
			}

		}

		MovementComponent& Entity::GetMovementComponent() const
		{
			return *m_MovComponent;
		}

		Sprite* Entity::GetSprite() const
		{
			if (m_Sprite != nullptr)
			{
				return m_Sprite;
			}

			return nullptr;
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
