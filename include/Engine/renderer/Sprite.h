//
// Created by semyon on 03.12.2019.
//

#ifndef MY_OWN_GAME_SPRITE_H
#define MY_OWN_GAME_SPRITE_H

#include "../Math/Vector2.hpp"
#include "../Math/Color3.hpp"

#include <memory>

#define DEFAULT_SPRITE_WIDTH 100
#define DEFAULT_SPRITE_HEIGHT 100
#define DEFAULT_POSITION_X 10
#define DEFAULT_POSITION_Y 10


namespace Engine
{

  class  Sprite {
    public:
        virtual ~Sprite() = default;


        static std::unique_ptr<Sprite> Create(const Math::Vector2<float> position,const Math::Vector2<float> size);

        virtual void SetTexture(const char* path) = 0;

        virtual void SetPosition(Math::Vector2<float> position) = 0;

        virtual void SetPosition(float x,float y) = 0;

        virtual void SetFillColor(Math::Color3<float> color3)= 0;

        virtual void SetScale(float ScaleFactorX,float ScaleFactorY) = 0;

        virtual void SetScale(Math::Vector2<float> factors) = 0;

        virtual void SetOrigin(float x,float y) = 0;

        virtual void SetOrigin(Math::Vector2<float> origin) = 0;

        virtual void SetRotation(float angle) = 0;


        virtual const Math::Vector2<float> & GetScale() const = 0;

        virtual const Math::Vector2<float> & GetOrigin() const = 0;

        virtual const float& GetRotation() const = 0;

        virtual Math::Vector2<float> GetPositions() const = 0;

        virtual Math::Color3<float> GetFillColor() = 0;

        virtual Math::Vector2<float> GetSize() const = 0;

    };
};


#endif //MY_OWN_GAME_SPRITE_H
