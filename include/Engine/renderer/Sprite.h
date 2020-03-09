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
#include "Drawable2D.h"


namespace Engine
{
	class Sprite : public Drawable2D
	{
	public:
		Sprite(std::shared_ptr<Texture2D> texture);
		
		Sprite(float x,float y,std::shared_ptr<Texture2D> texture);

		void MoveLeft(float time,float speed);
		void MoveRight(float time, float speed);
		void MoveUp(float time,float speed);
		void MoveDown(float time,float speed);

		void TransformRecalculate();

		void OnRender(Camera2D& camera) const override;
	private:
		std::shared_ptr<Shader> m_Shader;

		Rectangle* m_Rect;

	};
};


#endif //MY_OWN_GAME_SPRITE_H
