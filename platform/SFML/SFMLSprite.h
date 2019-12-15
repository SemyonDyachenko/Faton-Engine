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
    sf::RectangleShape* sprite;
    sf::Texture* texture;

    Engine::Math::Vector2<float> SpriteSize;
    Engine::Math::Vector2<float> SpritePosition;

    Engine::Math::Vector2<float> ScaleFactor;

    float Rotation;

    Engine::Math::Color3<float> fillColor;
public:
    //default constructor
    SFMLSprite();
    //with positions and size
    SFMLSprite(Engine::Math::Vector2<float> position,Engine::Math::Vector2<float> size);


    void SetPosition(Engine::Math::Vector2<float> position) override;

    void SetPosition(float x,float y) override;

    void SetFillColor(Engine::Math::Color3<float> color3) override;

    Engine::Math::Vector2<float> GetPositions() const override;

    void SetScale(float ScaleFactorX,float ScaleFactorY) override;

    void SetScale(Engine::Math::Vector2<float> factors) override;

    void SetOrigin(float x,float y) override;

    void SetOrigin(Engine::Math::Vector2<float> origin) override;

    void SetRotation(float angle) override;

    const Engine::Math::Vector2<float> & GetScale() const override;

    const Engine::Math::Vector2<float> & GetOrigin() const override;

    Engine::Math::Color3<float> GetFillColor() override;

    Engine::Math::Vector2<float> GetSize() const override;

    sf::RectangleShape GetAPISprite() const;


    void SetTexture(const char* path) override;


    //void Draw(Engine::Window & window) override;

    ~SFMLSprite() = default;
};


#endif //MY_OWN_GAME_SFMLSPRITE_H
