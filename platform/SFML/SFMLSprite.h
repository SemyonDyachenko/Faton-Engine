//
// Created by semyon on 07.12.2019.
//

#ifndef MY_OWN_GAME_SFMLSPRITE_H
#define MY_OWN_GAME_SFMLSPRITE_H


#include <SFML/Graphics.hpp>
#include "../../include/Engine/renderer/Sprite.h"



class SFMLSprite : public Engine::Sprite
{


private:
    sf::RectangleShape sprite;
    sf::Texture* texture;

    Engine::Math::Vector2<float> SpriteSize;
    Engine::Math::Vector2<float> SpritePosition;

    Engine::Math::Color3<float> fillColor;
public:
    //default constructor
    SFMLSprite();
    //with positions and size
    SFMLSprite(Engine::Math::Vector2<float> position,Engine::Math::Vector2<float> size);

    void SetFillColor(Engine::Math::Color3<float> color3) override;

    Engine::Math::Vector2<float> GetPositions() const override;

    Engine::Math::Vector2<float> GetSize() const override;

    void SetTexture(const char* path) override;

    virtual ~SFMLSprite();
};


#endif //MY_OWN_GAME_SFMLSPRITE_H
