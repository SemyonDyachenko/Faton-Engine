//
// Created by semyon on 03.12.2019.
//

#include "../../../include/Engine/renderer/Sprite.h"


namespace Engine
{


	Sprite::Sprite(float width,float height) : m_Width(width), m_Height(height)
	{
		this->withTexture = false;

		if (!withTexture)
		{
			this->texture = nullptr;
			this->rect = new Rectangle(0,0,m_Width, m_Height);
		}
		else
		{
			this->texture = Texture2D::Create(texturePath.c_str());
			this->rect = new Rectangle(0,0,texture->GetSize().x, texture->GetSize().y);
		}
	}

	Sprite::~Sprite()
	{
		
	}

	void Sprite::SetTexture(std::string path)
	{
		this->texturePath = path;
		this->withTexture = true;
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


	void Sprite::OnUpdate()
	{
	}

	
	void Sprite::OnRender()
	{
		
	}
}
