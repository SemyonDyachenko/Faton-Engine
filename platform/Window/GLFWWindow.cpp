//
// Created by semyon on 16.12.2019.
//

#include "GLFWWindow.h"

GLFWWindow::GLFWWindow(unsigned width, unsigned height, std::string& title)
{
}

GLFWWindow::~GLFWWindow()
{
}

Engine::Math::Vec2u GLFWWindow::GetSize() const
{
}

bool GLFWWindow::IsVerticalSyncEnable() const
{
}

bool GLFWWindow::isOpen() const
{
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
}

void GLFWWindow::SetVerticalSync(bool enabled)
{
}

float GLFWWindow::GetHeight() const
{
}

float GLFWWindow::GetWidth() const
{
}

void GLFWWindow::ChangeFrameRateLimit(unsigned frameRateLimit)
{
}

bool GLFWWindow::PollEvent(Engine::Event& event)
{
}

void GLFWWindow::Close()
{
}

void GLFWWindow::Draw(Engine::Sprite& sprite, Engine::Shader& shader)
{
}

void GLFWWindow::Draw(Engine::Sprite& sprite)
{
}
