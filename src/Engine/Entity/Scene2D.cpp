//
// Created by semyon on 01.12.2019.
//

#include "../../../include/Engine/Entity/Scene2D.h"


namespace Engine
{
	namespace Entity
	{

		Scene2D::Scene2D()
		{
			m_Entities.clear();
			m_ScenePause = false;
		}

		Scene2D::Scene2D(const float aspectRatio)
		{
			m_Camera = new Camera2D(aspectRatio);
			m_Entities.clear();
			m_ScenePause = false;
		}

		Scene2D::~Scene2D()
		{
			for (auto it = m_Entities.begin(); it != m_Entities.end(); it++)
			{
				delete it->second;
			}
		}

		void Scene2D::Update(float DeltaTime)
		{
			for (auto entity = m_Entities.begin(); entity != m_Entities.end(); entity++)
			{
				if (!m_ScenePause)
					entity->second->OnUpdate(DeltaTime);
			}
		}

		void Scene2D::AddEntity(std::string& entityName, Entity& entity)
		{
			m_Entities[entityName] = &entity;
		}

		void Scene2D::Start()
		{
			for (auto it = m_Entities.begin(); it != m_Entities.end(); it++)
			{
				it->second->OnRender(*m_Camera);
			}
		}
		inline Camera2D* Scene2D::GetCamera()
		{
			if (m_Camera)
			{
				return m_Camera;
			}
			else {
				return nullptr;
				std::cout << "Scene Camera is nullptr" << std::endl;
			}
		}
		inline std::map<std::string, Entity*>& Scene2D::GetEntities()
		{
			return this->m_Entities;
		}
	}
}
