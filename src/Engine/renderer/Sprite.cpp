//
// Created by semyon on 03.12.2019.
//

#include "../../../include/Engine/renderer/Sprite.h"
#include "../../../include/Engine/renderer/Renderer2D.h"


namespace Engine
{
	Sprite::Sprite(std::shared_ptr<Texture2D> texture) :
		Drawable2D(Math::Vec2f(0.0, 0.0),
			Math::Vec2f(static_cast<float>(texture->GetSize().x), static_cast<float>(texture->GetSize().y)))
	{
		m_Texture = texture;

		bounds.w = static_cast<float>(texture->GetSize().x) / 100;
		bounds.h = static_cast<float>(texture->GetSize().y) / 100;

		m_Rect = new Rectangle(0, 0, bounds.x, bounds.y);



		m_Shader = Shader::Create("Shaders/Texture/TextureVertexShader.glsl", "Shaders/Texture/TextureFragmentShader.glsl");
	}

	Sprite::Sprite(float x, float y, std::shared_ptr<Texture2D> texture) :
		Drawable2D(Math::Vec2f(x, y),
			Math::Vec2f(static_cast<float>(texture->GetSize().x), static_cast<float>(texture->GetSize().y)))
	{
		bounds.x = x;
		bounds.y = y;

		bounds.w = static_cast<float>(texture->GetSize().x) / 100;
		bounds.h = static_cast<float>(texture->GetSize().y) / 100;

		m_Texture = texture;
		m_Rect = new Rectangle(this->bounds.x, this->bounds.y, bounds.w, bounds.h);

		m_Shader = Shader::Create("Shaders/Texture/TextureVertexShader.glsl", "Shaders/Texture/TextureFragmentShader.glsl");
	}

	void Sprite::ChangeTexture(std::shared_ptr<Texture2D>& texture)
	{
		m_Texture = texture;
		TextureRecalculate();
	}



	void Sprite::MoveLeft(float time, float speed)
	{
		bounds.x += time * (-speed);
		SetPosition({ bounds.x,bounds.y });
		TransformRecalculate();
	}

	void Sprite::MoveRight(float time, float speed)
	{
		bounds.x += time * speed;
		SetPosition({ bounds.x,bounds.y });
		TransformRecalculate();
	}

	void Sprite::MoveUp(float time, float speed)
	{
		bounds.y += time * speed;
		SetPosition({ bounds.x,bounds.y });
		TransformRecalculate();
	}

	void Sprite::MoveDown(float time, float speed)
	{
		bounds.y += time * (-speed);
		SetPosition({ bounds.x,bounds.y });
		TransformRecalculate();
	}

	void Sprite::Move(float velocity_x, float velocity_y)
	{
		bounds.x += velocity_x;
		bounds.y += velocity_y;
		TransformRecalculate();
	}


	void Sprite::TextureRecalculate()
	{
		bounds.w = static_cast<float>(m_Texture->GetSize().x) / 100;
		bounds.h = static_cast<float>(m_Texture->GetSize().y) / 100;
	}

	void Sprite::TransformRecalculate()
	{
		m_Rect->SetPosition(bounds.x, bounds.y);
		m_Rect->SetSize(bounds.w, bounds.h);
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