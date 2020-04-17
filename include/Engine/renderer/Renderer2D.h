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
#include "../../../platform/Window/SFMLWindow.h"
#include "RectangleShape.h"


#include "../Entity/Scene2D.h"

namespace Engine {
	


	class Renderer2D {
    public:
        static void Init();

        static void BeginScene(Entity::Scene2D & scene);

        static void EndScene();

        static void DrawRect(Camera2D & camera,Engine::Math::Vector2<float>& positions,Engine::Math::Vector2<float>&size);
        static void DrawRect(Camera2D & camera,Engine::Math::Vector2<float> positions,Engine::Math::Vector2<float>size, Math::Vec4f color);
        static void DrawLight(Camera2D& camera, Math::Vec2f position, Math::Vec2f size, Math::Vec4f color);


		static void Render(Engine::Shape& primitive);

    };

    class RenderCommand
    {
    private:
        static std::unique_ptr<RendererAPI> m_RendererAPI;
    public:

    	static void Init3D()
    	{
			m_RendererAPI->Init3D();
    	}

        static void Init()
        {

            m_RendererAPI->Init();
        }

        static void Clear(Engine::Math::Color3<float>& color)
        {
            m_RendererAPI->Clear(color);
        }

        static void Clear(Window& window)
        {
            m_RendererAPI->Clear(window);

        }

		static void SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
        {
			m_RendererAPI->SetViewport(x, y, width, height);
        }


    };

}


#endif //MY_OWN_GAME_RENDERER2D_H
