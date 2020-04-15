#ifndef ENGINE_SCENE_2D_H
#define ENGINE_SCENE_2D_H


#include "Scene.h"

#include <map>

namespace Engine
{
	namespace Entity
	{
		class Scene2D : public Scene
		{
		public:
			Scene2D();

			Scene2D(const float aspectRatio);

			virtual ~Scene2D();

			void Update(float DeltaTime) override;
			
			void AddEntity(std::string& entityName,Entity& entity) override;

			void Start() override;

			inline Camera2D* GetCamera();

			inline std::map<std::string, Entity*>& GetEntities();

		private:
			std::map<std::string,Entity*> m_Entities;

			Camera2D *m_Camera;

			bool m_ScenePause;

			
		};
		
	}
}



#endif
