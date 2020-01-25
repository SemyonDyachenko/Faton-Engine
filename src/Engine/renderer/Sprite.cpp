//
// Created by semyon on 03.12.2019.
//

#include "../../../include/Engine/renderer/Sprite.h"
#include "../../../include/Engine/renderer/Renderer2D.h"


namespace Engine
{
	Sprite::Sprite(std::shared_ptr<Texture2D> texture) :
	Drawable2D(Math::Vec2f(0.0,0.0),
	Math::Vec2f(static_cast<float>(texture->GetSize().x),static_cast<float>(texture->GetSize().y)))
	{
		m_Texture = texture;
		m_Rect = new Rectangle(0, 0, static_cast<float>(texture->GetSize().x)/100, static_cast<float>(texture->GetSize().y)/100);
		
		m_Shader = Shader::Create("Shaders/Texture/TextureVertexShader.glsl", "Shaders/Texture/TextureFragmentShader.glsl");
	}

	Sprite::Sprite(float x, float y, std::shared_ptr<Texture2D> texture) :
	Drawable2D(Math::Vec2f(x,y),
	Math::Vec2f(static_cast<float>(texture->GetSize().x), static_cast<float>(texture->GetSize().y)))
	{
		m_Texture = texture;
		m_Rect = new Rectangle(x, y, static_cast<float>(texture->GetSize().x) / 100, static_cast<float>(texture->GetSize().y) / 100);

		m_Shader = Shader::Create("Shaders/Texture/TextureVertexShader.glsl", "Shaders/Texture/TextureFragmentShader.glsl");
	}

	void Sprite::OnRender(Camera2D& camera) const
	{
		m_Shader->Bind();

		m_Shader->SetMat4("ViewProjectionMatrix", camera.GetViewProjectionMatrix());

		m_Shader->SetMat4("Transform", m_Rect->GetTransform());
		
		m_Shader->SetInt("m_Texture", 0);
		
		m_Texture->Bind();
		
		Renderer2D::Render(*m_Rect);

		m_Shader->Unbind();
	}
}
