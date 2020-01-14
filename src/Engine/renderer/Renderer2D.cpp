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

	void Renderer2D::DrawRect(Engine::Math::Vec2f size)
	{
		float w = size.x;
		float h = size.y;

		std::shared_ptr<VertexArray> vao = VertexArray::Create();

		std::vector<float> vertices =
		{
			-w,-h,0,
			w,-h,0,
			w,h,0,
			-w,h,0
		};

		std::vector<unsigned int> indices =
		{
			0,1,3,
			3,1,2
		};


	
		vao->AddIndexBuffer(indices);
		vao->AddVertexBuffer(vertices);
		
		
		
		vao->GetDrawable()->Bind();
		vao->GetDrawable()->Draw();
    	
    	
	}


    void Renderer2D::RendererDraw(Sprite &sprite, Window &window, Shader &shader) {
       window.Draw(sprite,shader);
    }



    void Renderer2D::RendererDraw(Sprite& sprite, Window &window) {
       window.Draw(sprite);
   }

    void Renderer2D::Draw(Engine::Shape& primitive)
    {
		primitive.Draw();
    }
}
