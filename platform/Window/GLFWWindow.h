//
// Created by semyon on 16.12.2019.
//

#ifndef MY_OWN_GAME_GLFWWINDOW_H
#define MY_OWN_GAME_GLFWWINDOW_H


#include "../../include/Engine/Core/Window.h"


class GLFWWindow : public Engine::Window {

private:
	GLFWWindow* window;

	unsigned int Width, Height;
	std::string Title;
	bool Vsync;

	unsigned int FrameRateLimit;

	bool fullscreen;
	bool resizable;
public:
	GLFWWindow(unsigned width, unsigned height, std::string& title);

	virtual ~GLFWWindow();

	Engine::Math::Vec2u GetSize() const;

	bool IsVerticalSyncEnable() const override;

	bool isOpen() const override;

	void Clear(Engine::Math::Color3<float> color) override;

	void SetFullscreen(bool is_fullscreen) override;

	void SetResizable(bool resizable) override;

	void SetTitle(const char* title) override;

	void SetVerticalSync(bool enabled) override;

	float GetHeight() const override;
	float GetWidth() const override;

	void ChangeFrameRateLimit(unsigned frameRateLimit) override;

	bool PollEvent(Engine::Event& event) override;
	
	void Close() override;

	void Draw(Engine::Sprite& sprite, Engine::Shader& shader) override;
	void Draw(Engine::Sprite& sprite) override;

};


#endif //MY_OWN_GAME_GLFWWINDOW_H
