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


namespace Engine
{

	class Sprite
	{
	private:
		std::shared_ptr<Texture2D> texture;

		std::string texturePath;

		float m_Width;
		float m_Height;

		Math::Vec2f Position;

		bool withTexture;
		
		Rectangle *rect;
	public:
		Sprite(float width,float height);

		virtual ~Sprite();


		void SetTexture(std::string path);

		//control
		void SetPosition(Math::Vec2f & position);
		void SetPosition(float x, float y);

		void OnUpdate();

		void Translate(float x,float y);
		void Translate(Math::Vec2f& position);

		Shape& GetShape() const { }

		void OnRender();
	};
};


#endif //MY_OWN_GAME_SPRITE_H
