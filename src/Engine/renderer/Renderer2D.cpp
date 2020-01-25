//
// Created by semyon on 02.12.2019.
//

#include "../../../include/Engine/renderer/Renderer2D.h"


namespace Engine
{


    std::unique_ptr<RendererAPI> RenderCommand::m_RendererAPI = RendererAPI::Create();


    void Renderer2D::Init() {
		
    }

    void Renderer2D::BeginScene(Entity::Scene2D& scene)
    {
		scene.Start();
    }

   
    void Renderer2D::EndScene() {

    }

    void Renderer2D::DrawRect(Camera2D& camera, Engine::Math::Vector2<float>& positions,
	    Engine::Math::Vector2<float>& size)
    {
    	
    }

    void Renderer2D::DrawRect(Camera2D& camera, Engine::Math::Vector2<float>& positions,
	    Engine::Math::Vector2<float>& size, Engine::Math::Color3<float>& color3)
    {
    	
    }



    void Renderer2D::Render(Engine::Shape& primitive)
    {
		primitive.Draw();
    }
}
