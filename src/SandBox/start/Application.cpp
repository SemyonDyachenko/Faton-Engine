//
// Created by semyon on 01.12.2019.
//

#include "../../../include/SandBox/start/Application.h"
#include "../../../platform/Window/SFMLWindow.h"
#include "../../../platform/SFML/SFMLRendererAPI.h"
#include "../../../include/Engine/Events/AppEvent.h"
#include "../../../include/Engine/Engine.h"


Application::Application() {

    if(Engine::RendererAPI::Create() == std::unique_ptr<SFMLRendererAPI>())
    {
        this->window = new SFMLWindow(1920, 1080, "hello world");
    }

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

    Engine::Sprite * sprite = new SFMLSprite(Engine::Math::Vector2<float>(100,200),Engine::Math::Vector2<float>(100,200));



    this->window->Clear();
    this->window->Draw(*sprite);
    this->window->Show();

}

void Application::Run() {
    this->event = new Engine::WindowCloseEvent();
    while(window->isOpen()) {
        this->Update();
        this->Render();
    }
}




