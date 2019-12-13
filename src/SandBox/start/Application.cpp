//
// Created by semyon on 01.12.2019.
//

#include "../../../include/SandBox/start/Application.h"
#include "../../../platform/Window/SFMLWindow.h"
#include "../../../platform/SFML/SFMLRendererAPI.h"
#include "../../../include/Engine/Events/AppEvent.h"
#include "../../../include/Engine/Engine.h"
#include "../../../platform/SFML/SFMLSprite.h"


Application::Application() {

    this->window = Engine::Window::Create(1280,720,"HELLO");
}

Application::~Application() {

}

void Application::UpdateDeltaTime() {

}


void Application::Update() {
        while (window->PollEvent(*this->event)) {
            if(event->GetEventType() == Engine::EventType::WINDOW_CLOSE)
            {
            }

    }

}


void Application::Render() {
    std::unique_ptr<Engine::Sprite> sprite = Engine::Sprite::Create();

    

    this->window->Clear();
    this->window->Show();

}

void Application::Run() {
    this->event = new Engine::WindowCloseEvent();
    while(this->window->isOpen()) {
        this->Update();
        this->Render();
    }
}




