//
// Created by semyon on 03.12.2019.
//

#ifndef MY_OWN_GAME_SPRITE_H
#define MY_OWN_GAME_SPRITE_H

#include "../Math/Vector2.hpp"
#include "../Math/Color3.hpp"

#include <memory>

#include "Shape.h"
#include <string>
#include "Texture.h"
#include "RectangleShape.h"
#include "Shader.h"

namespace Engine
{

	class Sprite
	{
	public:
		Sprite(std::string texturePath);

		virtual ~Sprite();


		void SetTexture(std::string path);

		//control
		void SetPosition(Math::Vec2f & position);
		void SetPosition(float x, float y);

		void Translate(float x,float y);
		void Translate(Math::Vec2f& position);

		Shape& GetShape() const { return *m_Rect; }

		void OnRender();
		
	private:
		Rectangle *m_Rect;
		std::shared_ptr<Texture2D> m_Texture;
		std::shared_ptr<Shader> m_Shader;

		std::string m_TexturePath;

		unsigned int m_Width;
		unsigned int m_Height;

		Math::Vec2f Position;
	};
};


#endif //MY_OWN_GAME_SPRITE_H
