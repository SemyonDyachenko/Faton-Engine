//
// Created by semyon on 01.12.2019.
//

#include "../../../include/Engine/Entity/Scene2D.h"


namespace Engine
{
	Entity::Scene2D::Scene2D(Camera2D& camera)
	{
		m_Camera = &camera;
	}

	Entity::Scene2D::~Scene2D()
	{
		m_Entities.clear();
	}

	void Entity::Scene2D::AddEntity(Entity& entity)
	{
		m_Entities.push_back(&entity);
	}

	void Entity::Scene2D::Start()
	{
	}
}
