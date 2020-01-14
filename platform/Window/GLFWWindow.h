//
// Created by semyon on 16.12.2019.
//

#ifndef MY_OWN_GAME_GLFWWINDOW_H
#define MY_OWN_GAME_GLFWWINDOW_H


#include "../../include/Engine/Core/Window.h"


class GLFWWindow : public Engine::Window {

private:
	GLFWWindow* window;

	float Width, Height;

	unsigned int FrameRateLimit;

	bool fullscreen;
	bool resizable;
};


#endif //MY_OWN_GAME_GLFWWINDOW_H
