//
// Created by semyon on 14.12.2019.
//

#ifndef MY_OWN_GAME_SFMLINPUT_H
#define MY_OWN_GAME_SFMLINPUT_H

#include "../../include/Engine/Core/Input.h"

#include <SFML/Window/Joystick.hpp>

class SFMLInput : public Engine::Input
{
protected:
    bool isKeyPressedImplementation(int key) override;

	bool isButtonPressedImplementation(int button) override;

	Engine::Math::Vector2<float> GetMousePositionImplementation() override;

	float GetMousePositionXImplementation() override;

	float GetMousePositionYImplementation() override;

	bool GamepadIsConnectedImplementation(unsigned int gamepad) override;

	unsigned int GetGamepadButtonCountImplementation(unsigned int gamepad) override;

	bool GamepadHasAxisImplementation(unsigned int gamepad,Engine::Gamepad::Axis axis) override;

	bool GamepadIsButtonPressedInplementation(unsigned int gamepad, unsigned int button) override;

	float GamepadGetAxisPositionImplementation(unsigned int gamepad, Engine::Gamepad::Axis axis) override;
};


#endif //MY_OWN_GAME_SFMLINPUT_H
