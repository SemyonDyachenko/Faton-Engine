//
// Created by semyon on 01.12.2019.
//

#ifndef MY_OWN_GAME_SCENE_H
#define MY_OWN_GAME_SCENE_H


#include "../Camera/Camera.h"

namespace Engine {


    class Scene {
    public:
        Scene(Camera &camera);

        virtual ~Scene();

        virtual void Update() = 0;
        virtual void Render() = 0;

    };

    class Scene2D : public Scene
    {
    public:
        Scene2D(Camera& camera);

        virtual ~Scene2D();

        void Update() override;
        void Render() override;
    };
}

#endif //MY_OWN_GAME_SCENE_H
