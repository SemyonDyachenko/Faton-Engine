//
// Created by semyon on 01.12.2019.
//

#include "../../../include/SandBox/start/Application.h"
#include "../../../platform/Window/SFMLWindow.h"
#include "../../../platform/SFML/SFMLRendererAPI.h"
#include "../../../include/Engine/Events/AppEvent.h"


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
    this->event = new Engine::WindowCloseEvent();
    while(window->isOpen()) {
        while (window->PollEvent(*this->event)) {
            if(event->GetEventType() == Engine::EventType::WINDOW_CLOSE)
            {
                //this->window->SetEventType(Engine::EventType::WINDOW_CLOSE);
            }
        }
        this->window->Clear();


        this->window->Show();
    }
}


void Application::Render() {

}

void Application::Run() {
this->Update();
this->Render();
}




