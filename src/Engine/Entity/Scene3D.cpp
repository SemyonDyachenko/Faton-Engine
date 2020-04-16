#include "../../../include/Engine/Entity/Scene3D.h"


namespace Engine
{

	Entity::Scene3D::Scene3D(Camera3D& camera)
	{
		m_Camera = &camera;
	}

	Entity::Scene3D::~Scene3D()
	{
		m_Entities.clear();
	}

	void Entity::Scene3D::AddEntity(std::string& entityName, Entity& entity)
	{
	}



	void Entity::Scene3D::Start()
	{

	}

}