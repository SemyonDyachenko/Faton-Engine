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

	sprite = new Sprite(1,1,texture);

	
	sprite2 = new Sprite(6,6,texture);



	if(Collision::Intersects(FloatRect(sprite->GetBounds()),FloatRect(sprite2->GetBounds())))
	{
		FATON_PRINT(sprite->GetBounds().x);
		FATON_PRINT(sprite->GetBounds().y);
		FATON_PRINT(sprite->GetBounds().w);
		FATON_PRINT(sprite->GetBounds().h);
		FATON_PRINT(".....////////////////.............");
		FATON_PRINT(sprite2->GetBounds().x);
		FATON_PRINT(sprite2->GetBounds().y);
		FATON_PRINT(sprite2->GetBounds().w);
		FATON_PRINT(sprite2->GetBounds().h);
		FATON_PRINT("IS COLLIISION");
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




