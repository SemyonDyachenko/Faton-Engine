//
// Created by semyon on 01.12.2019.
//


#include "../../../include/SandBox/start/Application.h"
#include "../../../include/Engine/Physics/Collision.h"


void Application::InitGraphics()
{
	Renderer2D::Init();
	RenderCommand::Init();
}

Application::Application() {
	
    this->window = Window::Create(1280,720,"Faton Engine");
	this->InitGraphics();

	camera = new Camera2D(window->GetWidth() / window->GetHeight());
	
	std::shared_ptr<Texture2D> texture = Texture2D::Create("assets/images/pusheen.png");

	sprite = new Sprite(texture);

	
	
	sprite2 = new Sprite(texture);
	sprite->SetPosition({ 2, 2 });

	if(Collision::AABB(FloatRect(sprite->GetPosition().x,sprite->GetPosition().y,sprite->GetSize().x,sprite->GetSize().y),FloatRect(sprite2->GetPosition().x,sprite2->GetPosition().y,sprite2->GetSize().x,sprite2->GetSize().y)))
	{
		std::cout << "IS COLLIISION" << std::endl;
	}

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




