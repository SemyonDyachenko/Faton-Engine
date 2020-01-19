//
// Created by semyon on 02.12.2019.
//

#include "../../../include/Engine/renderer/Renderer2D.h"


namespace Engine
{

	
	
    std::unique_ptr<RendererAPI> RenderCommand::m_RendererAPI = RendererAPI::Create();


    void Renderer2D::Init() {
	
    }

    void Renderer2D::createScene(Engine::Camera &camera) {
	
    }

    void Renderer2D::endScene() {

    }

    void Renderer2D::DrawRect(Engine::Math::Vector2<float> &positions, Engine::Math::Vector2<float> &size,Engine::Math::Color3<float> &color3)
    {
       //return Engine::Sprite()

    }


    void Renderer2D::Draw(Engine::Shape& primitive)
    {
		primitive.Draw();
    }
}
