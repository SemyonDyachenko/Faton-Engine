//
// Created by semyon on 01.12.2019.
//


#include "../../../include/SandBox/start/Application.h"
#include "../../../include/Engine/Physics/Collision.h"
#include "../../../include/Engine/Entity/Components/MovementComponent.h"

namespace Engine {
	
}

void Application::InitGraphics()
{
	Renderer2D::Init();
	RenderCommand::Init();
}

Application::Application() {
	
    this->window = Window::Create(1280,720,"Faton Engine");
	this->InitGraphics();

	event = nullptr;

	camera = new Camera2D(window->GetWidth() / window->GetHeight());
	
	std::shared_ptr<Texture2D> texture = Texture2D::Create("assets/images/pusheen.png");

	sprite = new Sprite(1,1,texture);


	
	
	sprite2 = new Sprite(5,5,texture);


	std::cout << "Width: " << sprite->GetBounds().w << " " << "Height: " << sprite->GetBounds().h << "\n";
	std::cout << "X: " << sprite->GetBounds().x << " " << "Y: " << sprite->GetBounds().y << "\n";
	

}

Application::~Application() {
    this->window->Close();
}


void Application::OnUpdate() {

	
}



void Application::OnRender() {

	
	
	sprite->OnRender(*camera);


	
	sprite2->OnRender(*camera);
}

void Application::Run() {
    event = new WindowCloseEvent();
    while (window->isOpen()) {

		sf::Clock clock;
		float time =float(clock.getElapsedTime().asMicroseconds());
		clock.restart();
		time = time / 800;
    	
		camera->Update(time);
        window->PollEvent(*event);
		window->Clear({ 34, 38, 35,1 });
		OnUpdate();
        OnRender();

    	
        window->Show();

    }
}




