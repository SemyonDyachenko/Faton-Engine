//
// Created by semyon on 07.12.2019.
//

#include "SFMLSprite.h"



SFMLSprite::SFMLSprite() {
    this->Rotation = 0.0f;
    this->ScaleFactor = Engine::Math::Vector2<float>(0,0);
    this->SpriteSize = Engine::Math::Vector2<float>(DEFAULT_SPRITE_WIDTH,DEFAULT_SPRITE_HEIGHT);
    this->SpritePosition = Engine::Math::Vector2<float>(DEFAULT_POSITION_X,DEFAULT_POSITION_Y);

    this->sprite = new sf::RectangleShape();
    this->texture = nullptr;

    this->sprite->setSize(sf::Vector2f(
            static_cast<float>(this->SpriteSize.x),
            static_cast<float>(this->SpriteSize.y)
    ));

    this->sprite->setPosition(
            static_cast<float>(this->SpritePosition.x),
            static_cast<float>(this->SpritePosition.y)
    );
}

SFMLSprite::SFMLSprite(Engine::Math::Vector2<float> position, Engine::Math::Vector2<float> size) {
    this->Rotation = 0.0f;
    this->ScaleFactor = Engine::Math::Vector2<float>(0,0);
    this->SpriteSize = size;
    this->SpritePosition = position;
    this->fillColor = Engine::Math::Color3<float>(255,0,0,100);
    this->sprite = new sf::RectangleShape();
    this->sprite->setSize(sf::Vector2f(static_cast<float>(size.x),static_cast<float>(size.y)));
    this->sprite->setFillColor(sf::Color(fillColor.red,fillColor.green,fillColor.blue));
    this->sprite->setPosition(sf::Vector2f(static_cast<float>(position.x),static_cast<float>(position.y)));
    this->texture = nullptr;

    if(texture != nullptr)
        this->sprite->setTexture(this->texture);
}

void SFMLSprite::SetFillColor(Engine::Math::Color3<float> color3) {
    this->fillColor = color3;
}

Engine::Math::Vector2<float> SFMLSprite::GetPositions() const {
    return this->SpritePosition;
}

Engine::Math::Vector2<float> SFMLSprite::GetSize() const {
    return this->SpriteSize;
}

void SFMLSprite::SetTexture(const char *path) {
    this->texture->loadFromFile(path);
    this->sprite->setTexture(this->texture);
}

std::unique_ptr<Engine::Sprite> Engine::Sprite::Create(const Math::Vector2<float> position,const Math::Vector2<float> size)
{
    return std::unique_ptr<Engine::Sprite>();
}


Engine::Math::Color3<float> SFMLSprite::GetFillColor() {
    return this->fillColor;
}

void SFMLSprite::SetPosition(Engine::Math::Vector2<float> position) {

}

void SFMLSprite::SetPosition(float x, float y) {

}

void SFMLSprite::SetScale(float ScaleFactorX, float ScaleFactorY) {

}

void SFMLSprite::SetScale(const Engine::Math::Vector2<float> factors) {

}

void SFMLSprite::SetOrigin(float x, float y) {

}

void SFMLSprite::SetOrigin(const Engine::Math::Vector2<float> origin) {

}

void SFMLSprite::SetRotation(float angle) {

}

const Engine::Math::Vector2<float> &SFMLSprite::GetScale() const {
    return  Engine::Math::Vector2<float>(0,0);
}

const Engine::Math::Vector2<float> &SFMLSprite::GetOrigin() const {
    return  Engine::Math::Vector2<float>(0,0);
}

sf::RectangleShape SFMLSprite::GetAPISprite() const {
    return *this->sprite;
}

SFMLSprite::~SFMLSprite() {
delete this->texture;
}

sf::RectangleShape SFMLSprite::GetAPISprite() {
    return *this->sprite;
}

const float &SFMLSprite::GetRotation() const {
    return this->Rotation;
}



/*
void SFMLSprite::Draw(SFMLWindow &window) {
window.GetWindow().draw(this->sprite);
}

void SFMLSprite::Draw(Engine::Window &window) {

}*/

