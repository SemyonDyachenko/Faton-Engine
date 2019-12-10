//
// Created by semyon on 07.12.2019.
//

#include "SFMLSprite.h"
#include "SFMLRendererAPI.h"


SFMLSprite::SFMLSprite() {
this->SpriteSize = Engine::Math::Vector2<float>(DEFAULT_SPRITE_WIDTH,DEFAULT_SPRITE_HEIGHT);
this->SpritePosition = Engine::Math::Vector2<float>(DEFAULT_POSITION_X,DEFAULT_POSITION_Y);

this->sprite.setSize(sf::Vector2f(
        static_cast<float>(this->SpriteSize.x),
        static_cast<float>(this->SpriteSize.y)
        ));

this->sprite.setPosition(
        static_cast<float>(this->SpritePosition.x),
        static_cast<float>(this->SpritePosition.y)
        );
}

SFMLSprite::SFMLSprite(Engine::Math::Vector2<float> position, Engine::Math::Vector2<float> size) {
this->SpriteSize = size;
this->SpritePosition = position;
this->sprite.setFillColor(sf::Color(0,0,0,1));
this->sprite.setSize(sf::Vector2f(size.x,size.y));
if(this->texture == nullptr)
{

}
else
{
    this->sprite.setTexture(this->texture);
}
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
}

std::unique_ptr<Engine::Sprite> Engine::Sprite::Create()
{
    if(Engine::RendererAPI::Create() == std::unique_ptr<SFMLRendererAPI>()) {
        return std::unique_ptr<SFMLSprite>();
    }
    else
    {
        return nullptr;
    }
}


SFMLSprite::~SFMLSprite() {
delete this->texture;
}

std::unique_ptr<Engine::Drawable> Engine::Drawable::Create(Engine::DrawableTypes type) {
    if(type == Engine::DrawableTypes::SPRITE) {
        return std::unique_ptr<SFMLSprite>();
    }
}


