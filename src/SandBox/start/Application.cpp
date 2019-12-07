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
while(window)
}

void Application::Render() {

this->window->Show();
}

void Application::Run() {
this->Update();
this->Render();
}

void Application::PollEvent(Engine::Event &event) {

}


