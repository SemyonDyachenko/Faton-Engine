//
// Created by semyon on 03.12.2019.
//

#ifndef MY_OWN_GAME_SPRITE_H
#define MY_OWN_GAME_SPRITE_H

#include "../Math/Vector2.hpp"
#include "../Math/Color3.hpp"
#include "Drawable.h"

namespace Engine
{
 class Sprite : Engine::Drawable {
 public:
     virtual ~Sprite() = default;

     virtual void setTexture(const char* path) = 0;

     virtual void SetFillColor(Engine::Math::Color3<float> color3)= 0;

     virtual Math::Vector2<float> GetPositions() const = 0;

     virtual Math::Vector2<float> GetSize() const = 0;


 };

};


#endif //MY_OWN_GAME_SPRITE_H
