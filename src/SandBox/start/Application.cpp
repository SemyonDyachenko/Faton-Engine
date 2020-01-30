//
// Created by semyon on 01.12.2019.
//


#include "../../../include/SandBox/start/Application.h"
#include "../../../include/Engine/Scripts/Script.h"


void Application::InitRenderer()
{
	Engine::Renderer2D::Init();


	Engine::RenderCommand::Init();
}

Application::Application() {
	
    this->window = Engine::Window::Create(1280,720,"Faton Engine");

	
	this->InitRenderer();


	//-----TEST------------


}

Application::~Application() {
    this->window->Close();
}


void Application::Update() {

	
}



void Application::Render() {



}

void Application::Run() {
    event = new Engine::WindowCloseEvent();
    while (window->isOpen()) {

		sf::Clock clock;
		float time =float(clock.getElapsedTime().asMicroseconds());
		clock.restart();
		time = time / 800;
    	
    	
        window->PollEvent(*event);
		window->Clear({ 34, 38, 35,1 });
        Update();
        Render();

    	
        window->Show();

    }
}




