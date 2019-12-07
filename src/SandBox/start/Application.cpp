//
// Created by semyon on 01.12.2019.
//

#include "../../../include/SandBox/start/Application.h"


Application::Application() {

this->window = Engine::Window::Create();


}

Application::~Application() {

}

void Application::UpdateDeltaTime() {

}


void Application::Update() {
    while(window->isOpen()) {
        while (window->PollEvent()) {

        }

    }
}


void Application::Render() {

}

void Application::Run() {
this->Update();
this->Render();
}




