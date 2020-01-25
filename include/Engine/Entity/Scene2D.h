#ifndef ENGINE_SCENE_2D_H
#define ENGINE_SCENE_2D_H


#include "Scene.h"


namespace Engine
{
	namespace Entity
	{
		class Scene2D : public Scene
		{
		public:
			Scene2D(Camera2D & camera);

			virtual ~Scene2D();
			
			void AddEntity(Entity& entity) override;

			void Start() override;

		private:
			std::vector<Entity*> m_Entities;

			Camera2D *m_Camera;
		};
		
	}
}



#endif
