//
// Created by semyon on 03.12.2019.
//

#ifndef MY_OWN_GAME_SPRITE_H
#define MY_OWN_GAME_SPRITE_H

#include "../Math/Vector2.hpp"
#include "../Math/Color3.hpp"
#include "Drawable.h"

#include <memory>

#define DEFAULT_SPRITE_WIDTH 100
#define DEFAULT_SPRITE_HEIGHT 100
#define DEFAULT_POSITION_X 10
#define DEFAULT_POSITION_Y 10


namespace Engine
{

    class Sprite {
    public:
        virtual ~Sprite() = default;

        virtual void SetTexture(const char* path) = 0;

        virtual void SetFillColor(Engine::Math::Color3<float> color3)= 0;

        virtual Math::Vector2<float> GetPositions() const = 0;


       // virtual void Draw(Window & window) = 0;


        virtual Math::Vector2<float> GetSize() const = 0;


        static std::unique_ptr<Sprite> Create();
    };
};


#endif //MY_OWN_GAME_SPRITE_H
