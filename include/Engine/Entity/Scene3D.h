#ifndef ENGINE_SCENE_3D_H
#define ENGINE_SCENE_3D_H


#include "Scene.h"
#include "../Camera/Camera3D.h"


namespace Engine
{

	namespace Entity
	{
		class Scene3D : public Scene
		{
		public:
			Scene3D(Camera3D & camera);

			virtual ~Scene3D();
			
			void AddEntity(Entity& entity) override;

			void Start() override;
		private:
			std::vector<Entity*> m_Entities;

			Camera3D * m_Camera;
		};
		
		
	}
	
}


#endif 