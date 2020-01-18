//
// Created by semyon on 03.12.2019.
//

#include "../../../include/Engine/renderer/Sprite.h"
#include "../../../include/Engine/renderer/Renderer2D.h"


namespace Engine
{


	Sprite::Sprite(std::string texturePath) :m_TexturePath(texturePath)
	{
		m_Texture = Texture2D::Create(texturePath.c_str());

		m_Width = m_Texture->GetSize().x;
		m_Height = m_Texture->GetSize().y;

		Position.x = 0;
		Position.y = 0;

		m_Shader = Shader::Create("Shaders/Texture/TextureVertexShader.glsl", "Shaders/Texture/TextureFragmentShader.glsl");
		m_Rect = new Rectangle(Position.x, Position.y, m_Texture->GetSize().x, m_Texture->GetSize().y);

		
	}

	Sprite::~Sprite()
	{
		delete m_Rect;
	}

	

	void Sprite::SetPosition(Math::Vec2f& position)
	{
		Position = position;
	}

	void Sprite::SetPosition(float x, float y)
	{
		Position = { x,y };
	}


	void Sprite::Translate(float x, float y)
	{
		Position.x = Position.x + x;
		Position.y = Position.y + y;
	}

	void Sprite::Translate(Math::Vec2f& position)
	{
		Position.x = Position.x + position.x;
		Position.y = Position.y + position.y;
	}

	void Sprite::OnRender()
	{

		m_Texture->Bind();
		m_Shader->SetInt("m_Texture", 0);
		Renderer2D::Draw(*m_Rect);
	}
}
