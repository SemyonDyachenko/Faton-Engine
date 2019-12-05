//
// Created by semyon on 02.12.2019.
//

#ifndef MY_OWN_GAME_RENDERER2D_H
#define MY_OWN_GAME_RENDERER2D_H

#include "../Camera/Camera.h"
#include "RendererAPI.h"
#include "../Core/Window.h"

namespace Engine {

    class Renderer2D {
    public:
        Renderer2D();
        virtual ~Renderer2D();

        static void Init();

        static void createScene(Engine::Camera& camera);
        static void endScene();



    };

    class RenderCommand
    {
    private:
        static std::unique_ptr<RendererAPI> m_RendererAPI;
    public:

        static void Init()
        {
            m_RendererAPI->Create();
            m_RendererAPI->Init();
        }

        static void Clear(Window& window)
        {
            m_RendererAPI->Clear(window);

        }

        static void Draw(Window& window)
        {
            m_RendererAPI->Draw(window);
        }

    };



}


#endif //MY_OWN_GAME_RENDERER2D_H
