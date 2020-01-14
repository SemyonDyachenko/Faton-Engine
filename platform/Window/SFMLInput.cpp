//
// Created by semyon on 14.12.2019.
//

#include <SFML/Window/Keyboard.hpp>
#include "SFMLInput.h"


std::unique_ptr<Engine::Input> Engine::Input::instance = std::make_unique<SFMLInput>();

bool SFMLInput::isKeyPressedImplementation(int key)
{

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(key)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SFMLInput::isButtonPressedImplementation(int button)
{
	return false;
}

Engine::Math::Vector2<float> SFMLInput::GetMousePositionImplementation()
{
	return Engine::Math::Vec2f(0,0);
}

float SFMLInput::GetMousePositionXImplementation()
{
	return 0.0f;
}

float SFMLInput::GetMousePositionYImplementation()
{
	return 0.0f;
}

