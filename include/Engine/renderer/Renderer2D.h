//
// Created by semyon on 02.12.2019.
//

#ifndef MY_OWN_GAME_RENDERER2D_H
#define MY_OWN_GAME_RENDERER2D_H

#include "../Camera/Camera.h"

namespace Engine {

    class Renderer2D {
    public:
        Renderer2D();
        virtual ~Renderer2D();

        static void Init();

        static void BeginScene(Engine::Camera& camera);
        static void ENdScene();



    };

}


#endif //MY_OWN_GAME_RENDERER2D_H
