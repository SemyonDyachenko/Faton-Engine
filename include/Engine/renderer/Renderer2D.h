//
// Created by semyon on 02.12.2019.
//

#ifndef MY_OWN_GAME_RENDERER2D_H
#define MY_OWN_GAME_RENDERER2D_H

#include "../Camera/Camera.h"
#include "RendererAPI.h"

#include "../Math/Color3.hpp"
#include "Sprite.h"
#include "Shader.h"


namespace Engine {

    class Renderer2D {
    public:
        Renderer2D();
        virtual ~Renderer2D();

        static void Init();

        static void createScene(Engine::Camera& camera);

        static void endScene();

        static void DrawRect(Engine::Math::Vector2<float>& positions,Engine::Math::Vector2<float>&size,Engine::Math::Color3<float>& color3);

        static void RendererDraw(Sprite& sprite,Window&window);

        static void RendererDraw(Sprite& sprite,Window& window,Shader&shader);



    };

    class RenderCommand
    {
    private:
        static std::unique_ptr<RendererAPI> m_RendererAPI;
    public:

        static void Init()
        {

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
