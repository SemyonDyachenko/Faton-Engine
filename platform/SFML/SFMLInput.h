//
// Created by semyon on 14.12.2019.
//

#ifndef MY_OWN_GAME_SFMLINPUT_H
#define MY_OWN_GAME_SFMLINPUT_H

#include "../../include/Engine/Core/Input.h"

class SFMLInput : protected Engine::Input
{
protected:
    bool isKeyPressedImplementation(int key) override;

};


#endif //MY_OWN_GAME_SFMLINPUT_H
