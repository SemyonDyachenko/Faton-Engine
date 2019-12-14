//
// Created by semyon on 07.12.2019.
//

#include "SFMLSprite.h"



SFMLSprite::SFMLSprite() {
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
    this->SpriteSize = size;
    this->SpritePosition = position;
    this->sprite = new sf::RectangleShape();
    this->sprite->setSize(sf::Vector2f(static_cast<float>(size.x),static_cast<float>(size.y)));
    this->sprite->setFillColor(sf::Color(65,130,75,100));
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

std::unique_ptr<Engine::Sprite> Engine::Sprite::Create()
{
    return std::make_unique<SFMLSprite>();
}



SFMLSprite::~SFMLSprite() {
    delete this->texture;
}



/*
void SFMLSprite::Draw(SFMLWindow &window) {
window.GetWindow().draw(this->sprite);
}

void SFMLSprite::Draw(Engine::Window &window) {

}*/

