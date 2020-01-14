//
// Created by semyon on 14.12.2019.
//

#ifndef MY_OWN_GAME_SFMLINPUT_H
#define MY_OWN_GAME_SFMLINPUT_H

#include "../../include/Engine/Core/Input.h"

class SFMLInput : public Engine::Input
{
protected:
    bool isKeyPressedImplementation(int key) override;

	bool isButtonPressedImplementation(int button) override;

	Engine::Math::Vector2<float> GetMousePositionImplementation() override;

	float GetMousePositionXImplementation() override;

	float GetMousePositionYImplementation() override;

};


#endif //MY_OWN_GAME_SFMLINPUT_H
