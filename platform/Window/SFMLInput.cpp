//
// Created by semyon on 14.12.2019.
//

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
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
	return Engine::Math::Vec2f(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);
}

float SFMLInput::GetMousePositionXImplementation()
{
	return sf::Mouse::getPosition().x;
}

float SFMLInput::GetMousePositionYImplementation()
{
	return sf::Mouse::getPosition().y;
}

bool SFMLInput::GamepadIsConnectedImplementation(unsigned int gamepad)
{
	if (sf::Joystick::isConnected(gamepad))
	{
		return true;
	}
	else {
		return false;
	}
}

unsigned int SFMLInput::GetGamepadButtonCountImplementation(unsigned int gamepad)
{
	return sf::Joystick::getButtonCount(gamepad);
}

bool SFMLInput::GamepadHasAxisImplementation(unsigned int gamepad, Engine::Gamepad::Axis axis)
{
	if (axis == Engine::Gamepad::Axis::X)
	{
		if (sf::Joystick::hasAxis(gamepad, sf::Joystick::Axis::X))
		{
			return true;
		}
		else {
			return false;
		}
	}
	else if (axis == Engine::Gamepad::Axis::Y)
	{
		if (sf::Joystick::hasAxis(gamepad, sf::Joystick::Axis::Y))
		{
			return true;
		}
		else {
			return false;
		}
	}
	else if (axis == Engine::Gamepad::Axis::Z)
	{
		if (sf::Joystick::hasAxis(gamepad, sf::Joystick::Axis::Z))
		{
			return true;
		}
		else {
			return false;
		}
	}
	else if (axis == Engine::Gamepad::Axis::R)
	{
		if (sf::Joystick::hasAxis(gamepad, sf::Joystick::Axis::R))
		{
			return true;
		}
		else {
			return false;
		}
	}
	else if (axis == Engine::Gamepad::Axis::V)
	{
		if (sf::Joystick::hasAxis(gamepad, sf::Joystick::Axis::V))
		{
			return true;
		}
		else {
			return false;
		}
	}
	else if (axis == Engine::Gamepad::Axis::U)
	{
		if (sf::Joystick::hasAxis(gamepad, sf::Joystick::Axis::U))
		{
			return true;
		}
		else {
			return false;
		}
	}
	else if (axis == Engine::Gamepad::Axis::PovX)
	{
		if (sf::Joystick::hasAxis(gamepad, sf::Joystick::Axis::PovX))
		{
			return true;
		}
		else {
			return false;
		}
	}
	else if (axis == Engine::Gamepad::Axis::PovY)
	{
		if (sf::Joystick::hasAxis(gamepad, sf::Joystick::Axis::PovY))
		{
			return true;
		}
		else {
			return false;
		}
	}
}

bool SFMLInput::GamepadIsButtonPressedInplementation(unsigned int gamepad, unsigned int button)
{
	if (sf::Joystick::isButtonPressed(gamepad, button))
	{
		return true;
	}
	else {
		return false;
	}
}

float SFMLInput::GamepadGetAxisPositionImplementation(unsigned int gamepad, Engine::Gamepad::Axis axis)
{
	if (axis == Engine::Gamepad::Axis::X)
	{
		return sf::Joystick::getAxisPosition(gamepad, sf::Joystick::Axis::X);
	}
	else if (axis == Engine::Gamepad::Axis::Y)
	{
		return sf::Joystick::getAxisPosition(gamepad, sf::Joystick::Axis::Y);
	}
	else if (axis == Engine::Gamepad::Axis::Z)
	{
		return sf::Joystick::getAxisPosition(gamepad, sf::Joystick::Axis::Z);
	}
	else if (axis == Engine::Gamepad::Axis::R)
	{
		return sf::Joystick::getAxisPosition(gamepad, sf::Joystick::Axis::R);
	}
	else if (axis == Engine::Gamepad::Axis::V)
	{
		return sf::Joystick::getAxisPosition(gamepad, sf::Joystick::Axis::V);
	}
	else if (axis == Engine::Gamepad::Axis::U)
	{
		return sf::Joystick::getAxisPosition(gamepad, sf::Joystick::Axis::U);
	}
	else if (axis == Engine::Gamepad::Axis::PovX)
	{
		return sf::Joystick::getAxisPosition(gamepad, sf::Joystick::Axis::PovX);
	}
	else if (axis == Engine::Gamepad::Axis::PovY)
	{
		return sf::Joystick::getAxisPosition(gamepad, sf::Joystick::Axis::PovY);
	}
}

void SFMLInput::SetMousePositionImplementation(float x, float y)
{
	sf::Mouse::setPosition(sf::Vector2i(x, y));
}

