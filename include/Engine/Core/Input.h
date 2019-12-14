//
// Created by semyon on 14.12.2019.
//

#ifndef MY_OWN_GAME_INPUT_H
#define MY_OWN_GAME_INPUT_H

#include <memory>
#include "../Math/Vector2.hpp"

namespace Engine
{
    class Input
    {
    private:
        static std::unique_ptr<Input> instance;
    protected:
        Input() = default;

        virtual bool isKeyPressedImplementation(int key) = 0;
        virtual bool isButtonPressedImplementation(int button) = 0;
        virtual Engine::Math::Vector2<float> GetMousePositionImplementation() = 0;
        virtual float GetMousePositionXImplementation() = 0;
        virtual float GetMousePositionYImplementation() = 0;
    public:

        static bool IsKeyPressed(int key) {
            return instance->isKeyPressedImplementation(key);
        }

        static bool isMouseButtonPressed(int button)
        {
            return instance->isButtonPressedImplementation(button);
        }

        static Engine::Math::Vector2<float> GetMousePosition()
        {
            return instance->GetMousePositionImplementation();
        }

        static float GetMousePositionX()
        {
            return instance->GetMousePositionXImplementation();
        }

        static float GetMousePositionY()
        {
            return instance->GetMousePositionYImplementation();
        }


    };

}

#endif //MY_OWN_GAME_INPUT_H
