//
// Created by semyon on 01.12.2019.
//

#ifndef MY_OWN_GAME_SCENE_H
#define MY_OWN_GAME_SCENE_H


#include "../Camera/Camera.h"

#include <vector>
#include "../Entity/Entity.h"

namespace Engine {



    class Scene2D
    {
    public:
        Scene2D(Camera& camera);

        virtual ~Scene2D();

        void OnUpdate();
        void OnRender();
    private:
		Camera * m_Camera;
    	
		std::vector<Entity::Entity*> m_Entities;
    };
}

#endif //MY_OWN_GAME_SCENE_H
