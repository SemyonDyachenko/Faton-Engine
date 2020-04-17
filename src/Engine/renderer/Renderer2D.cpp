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
        std::shared_ptr<Shader> m_Shader = Shader::Create("Shaders/Color/ColorVertexShader.glsl", "Shaders/Color/ColorFragmentShader.glsl");

		Rectangle * m_rect = new Rectangle(positions.x, positions.y, size.x, size.y);
    	
		glm::mat4 m_Transform = translate(glm::mat4(1.0f), { positions.x,positions.y,0 }) * scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });
    	
		m_Shader->Bind();

		m_Shader->SetMat4("ViewProjectionMatrix", camera.GetViewProjectionMatrix());

		m_Shader->SetFloat4("u_Color", { 23,120,65,1 });
    	
		m_Shader->SetMat4("Transform", m_rect->GetTransform());

		Render(*m_rect);
    	
		m_Shader->Unbind();
    }

    void Renderer2D::DrawRect(Camera2D& camera, Engine::Math::Vector2<float> positions,
	    Engine::Math::Vector2<float> size,Math::Vec4f color)
    {
        std::shared_ptr<Shader> m_Shader = Shader::Create("Shaders/Color/ColorVertexShader.glsl", "Shaders/Color/ColorFragmentShader.glsl");

        Rectangle* m_rect = new Rectangle(positions.x, positions.y, size.x, size.y);

        glm::mat4 m_Transform = translate(glm::mat4(1.0f), { positions.x,positions.y,0 }) * scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });

        m_Shader->Bind();

        m_Shader->SetMat4("ViewProjectionMatrix", camera.GetViewProjectionMatrix());

        m_Shader->SetFloat4("u_Color", color);

        m_Shader->SetMat4("Transform", m_rect->GetTransform());

        Render(*m_rect);

        m_Shader->Unbind();
    }



    void Renderer2D::Render(Engine::Shape& primitive)
    {
		primitive.Draw();
    }
}
