//
// Created by semyon on 14.12.2019.
//

#ifndef MY_OWN_GAME_INPUT_H
#define MY_OWN_GAME_INPUT_H

#include <memory>
#include "../Math/Vector2.hpp"

namespace Engine
{

    enum {Count = 8,ButtonCount = 32,AxisCount =8};

    namespace Gamepad
    {

        enum Axis {
            X, Y, Z, R,
            U, V,
            PovX, PovY
        };
    }


    class Input
    {
  
    protected:
        Input() = default;

  
    public:
		Input(const Input&) = delete;

    	
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

        static bool GamepadIsConnected(unsigned int gamepad)
        {
            return instance->GamepadIsConnectedImplementation(gamepad);
        }

        static unsigned int GetGamepadButtonCount(unsigned int gamepad)
        {
            return instance->GetGamepadButtonCountImplementation(gamepad);
        }

        static bool GamepadHasAxis(unsigned int gamepad, Gamepad::Axis axis)
        {
            return instance->GamepadHasAxisImplementation(gamepad, axis);
        }

        static bool GamepadIsButtonPressed(unsigned int gamepad, unsigned int button)
        {
            return instance->GamepadIsButtonPressedInplementation(gamepad, button);
        }
        
        static float GamepadGetAxisPosition(unsigned int gamepad, Gamepad::Axis axis)
        {
            return instance->GamepadGetAxisPositionImplementation(gamepad, axis);
        }

        static float GetMousePositionX()
        {
            return instance->GetMousePositionXImplementation();
        }

        static float GetMousePositionY()
        {
            return instance->GetMousePositionYImplementation();
        }

		static void SetMousePosition(float x, float y)
		{
			return instance->SetMousePositionImplementation(x, y);
		}

		static void SetMousePosition(Math::Vec2f & position)
		{
			return instance->SetMousePositionImplementation(position.x,position.y);
		}

		virtual ~Input() = default;

    protected:
		virtual bool isKeyPressedImplementation(int key) = 0;
		virtual bool isButtonPressedImplementation(int button) = 0;
		virtual Math::Vector2<float> GetMousePositionImplementation() = 0;
		virtual float GetMousePositionXImplementation() = 0;
		virtual float GetMousePositionYImplementation() = 0;
        virtual bool GamepadIsConnectedImplementation(unsigned int gamepad) = 0;
        virtual unsigned int GetGamepadButtonCountImplementation(unsigned int gamepad) = 0;
        virtual bool GamepadHasAxisImplementation(unsigned int gamepad, Gamepad::Axis axis) = 0;;
        virtual bool GamepadIsButtonPressedInplementation(unsigned int gamepad, unsigned int button) = 0;
        virtual float GamepadGetAxisPositionImplementation(unsigned int gamepad, Gamepad::Axis axis) = 0;
		virtual void SetMousePositionImplementation(float x, float y) = 0;
        
		
	private:
		static std::unique_ptr<Input> instance;
    };

}

#endif //MY_OWN_GAME_INPUT_H
