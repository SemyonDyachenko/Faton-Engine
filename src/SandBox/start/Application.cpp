//
// Created by semyon on 01.12.2019.
//


#include "../../../include/SandBox/start/Application.h"




Application::Application() {

    this->window = Engine::Window::Create(1280,720,"ENGINE WINDOW");

}

Application::~Application() {
    this->window->Close();
}

void Application::UpdateDeltaTime() {
sf::Clock clock;
float time = float(clock.restart().asMilliseconds());
Engine::Time timer = time - lastFrameTime;
lastFrameTime = time;

}


void Application::Update() {
this->UpdateDeltaTime();

}


void Application::Render() {
    std::unique_ptr<Engine::Sprite> sprite = Engine::Sprite::Create(Engine::Math::Vector2<float>(10,10),Engine::Math::Vector2<float>(100,100));


   // Engine::Renderer2D::RendererDraw(sprite,*this->window);
}

void Application::Run() {
    this->event = new Engine::WindowCloseEvent();
    while (this->window->isOpen()) {
        window->PollEvent(*event);
        this->Update();
        this->window->Clear(Engine::Math::Color3<float>(160,80,80,100));

        this->Render();

        this->window->Show();

    }
}




