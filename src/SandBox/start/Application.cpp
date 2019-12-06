//
// Created by semyon on 01.12.2019.
//

#include "../../../include/SandBox/start/Application.h"


Application::Application() {
this->window = Engine::Window::Create();
}

Application::~Application() {

}

void Application::Update() {

}

void Application::Render() {
this->window->Create();
}

void Application::Run() {

}

