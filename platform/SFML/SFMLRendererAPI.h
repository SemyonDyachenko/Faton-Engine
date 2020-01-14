//
// Created by semyon on 03.12.2019.
//

#ifndef MY_OWN_GAME_SFML_RENDERER_API_H
#define MY_OWN_GAME_SFML_RENDERER_API_H

#include "../../include/Engine/renderer/RendererAPI.h"
#include "../../include/Engine/Core/Window.h"
#include "../Window/SFMLWindow.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class SFMLRendererAPI : public Engine::RendererAPI
{
public:
    SFMLRendererAPI();


    virtual void Init() override;

    virtual void Draw(Engine::VertexArray*vertexArray) override;

	virtual void SetViewport(unsigned x, unsigned y, unsigned width, unsigned height) override;
	
    virtual void Clear(Engine::Math::Color3<float>& color) override;

	
    virtual void Clear(Engine::Window & window) override;
};


#endif //MY_OWN_GAME_SFMLRENDERERAPI_H
