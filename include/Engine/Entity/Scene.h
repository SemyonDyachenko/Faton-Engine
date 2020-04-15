//
// Created by semyon on 01.12.2019.
//

#ifndef MY_OWN_GAME_SCENE_H
#define MY_OWN_GAME_SCENE_H


#include "../Camera/Camera.h"

#include <vector>
#include "../Entity/Entity.h"

namespace Engine {

	namespace Entity
	{

		class Scene
		{
		public:
			virtual void AddEntity(std::string & entityName,Entity& entity) = 0;

			virtual void Update(float DeltaTime) = 0;

			virtual ~Scene() = default;

			virtual void Start() = 0;
		};

	}
}

#endif //MY_OWN_GAME_SCENE_H
