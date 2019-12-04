//
// Created by semyon on 03.12.2019.
//

#ifndef MY_OWN_GAME_SFML_RENDERER_API_H
#define MY_OWN_GAME_SFML_RENDERER_API_H

#include "../../include/Engine/renderer/RendererAPI.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class SFMLRendererAPI : public Engine::RendererAPI
{
public:
    virtual void Init() override;

    virtual void Clear() override;

};


#endif //MY_OWN_GAME_SFMLRENDERERAPI_H
