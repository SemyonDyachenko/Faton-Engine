//
// Created by semyon on 01.12.2019.
//


#include "../../../include/SandBox/start/Application.h"



Application::Application() {

    this->window = Engine::Window::Create(1280,720,"ENGINE WINDOW");

}

Application::~Application() {

}

void Application::UpdateDeltaTime() {

}


void Application::Update() {


}


void Application::Render() {
    std::unique_ptr<Engine::Sprite> sprite = Engine::Sprite::Create();

}

void Application::Run() {
    this->event = new Engine::WindowCloseEvent();
    while (this->window->isOpen()) {
        window->PollEvent(*event);

        this->window->Clear(Engine::Math::Color3<float>(160,80,80,100));

        this->window->Show();

    }
}




