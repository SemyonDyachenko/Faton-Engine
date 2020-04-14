//
// Created by semyon on 16.12.2019.
//

#include "GLFWWindow.h"

GLFWWindow::GLFWWindow(unsigned width, unsigned height, std::string& title)
{
	Width = width;
	Height = height;
	Title = title;

	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
	Window = glfwCreateWindow((int)Width, (int)Height, title.c_str(), nullptr, nullptr);

}

GLFWWindow::~GLFWWindow()
{
}

Engine::Math::Vec2u GLFWWindow::GetSize() const
{
	return Engine::Math::Vec2u(Width, Height);
}

bool GLFWWindow::IsVerticalSyncEnable() const
{
	return Vsync;
}

bool GLFWWindow::isOpen() const
{
	return glfwWindowShouldClose(Window);
}

void GLFWWindow::Clear(Engine::Math::Color3<float> color)
{
}

void GLFWWindow::SetFullscreen(bool is_fullscreen)
{
}



void GLFWWindow::SetResizable(bool resizable)
{
}

void GLFWWindow::SetTitle(const char* title)
{
	Title = title;
}

void GLFWWindow::SetVerticalSync(bool enabled)
{
	if(enabled)
	{
		glfwSwapInterval(1);
	}
	else
	{
		glfwSwapInterval(0);
	}
	Vsync = enabled;
}

float GLFWWindow::GetHeight() const
{
	return (float)Height;
}

float GLFWWindow::GetWidth() const
{
	return (float)Width;
}

void GLFWWindow::ChangeFrameRateLimit(unsigned frameRateLimit)
{
}

bool GLFWWindow::PollEvent(Engine::Event& event)
{
	return false;
}

void GLFWWindow::Close()
{
	glfwDestroyWindow(this->Window);
	glfwTerminate();
}

void GLFWWindow::Draw(Engine::Sprite& sprite, Engine::Shader& shader)
{
}

void GLFWWindow::Draw(Engine::Sprite& sprite)
{
}


void GLFWWindow::Show()
{

	glfwSwapBuffers(Window);
	glfwPollEvents();
}


//WINDOW CREATE 

