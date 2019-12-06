//
// Created by semyon on 02.12.2019.
//

#ifndef MY_OWN_GAME_RENDERERAPI_H
#define MY_OWN_GAME_RENDERERAPI_H

#include <iostream>

#include "../Core/Window.h"
#include "../Core/Core.h"
#include <memory>

namespace Engine {

    class RendererAPI {
    public:
        enum class API {
            NONE = 0,
            OPENGL = 1,
            SFML = 2,
        };

    private:
        static API m_API;
    public:


        virtual void Init() = 0;

        virtual void Clear(Window & window) = 0;

        virtual void Draw(Window & window) = 0;


        inline static API getAPI();

        static std::unique_ptr<RendererAPI> Create();

    };


}


#endif //MY_OWN_GAME_RENDERERAPI_H
