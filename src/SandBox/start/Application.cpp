//
// Created by semyon on 01.12.2019.
//


#include "../../../include/SandBox/start/Application.h"
#include "../../../include/Engine/Physics/Collision.h"
#include "../../../include/Engine/Entity/Components/MovementComponent.h"




void Application::InitAPI()
{
	Renderer2D::Init();
	RenderCommand::Init();
}

void Application::InitWindow()
{
	this->Win_Width = 1280;
	this->Win_Height = 720;
	this->WinTittle = "Window";
	this->FullScreen = false;
	this->FrameRateLimit = 120;
	this->Vsync = false;
	
	this->window = Window::Create(static_cast<float>(Win_Width),static_cast<float>(Win_Height), WinTittle.c_str());
	this->window->SetFullscreen(FullScreen);
	this->window->SetVerticalSync(Vsync);
	this->window->SetResizable(false);
	this->window->ChangeFrameRateLimit(FrameRateLimit);
}

void Application::InitStates()
{
	//this->states.push(new MainMenuState());
}

Application::Application() {
	this->InitAPI();
	this->InitWindow();
	this->InitStates();

	this->deltaTime = new Time(0.0f);
}

Application::~Application() {
    this->window->Close();

	while(!states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

void Application::UpdateDeltaTime()
{
	float time = (float)glfwGetTime();
	deltaTime = new Time(float(time - LastFrameTime) / 1000);
	LastFrameTime = time;
}


void Application::OnUpdate() {
	
	window->PollEvent(*event);
	
} 




void Application::OnRender() {
	
	window->Clear({ 34, 38, 35,1 });


	Camera2D * camera = new Camera2D(window->GetWidth() / window->GetHeight());

	std::shared_ptr<Texture2D> t = Texture2D::Create("assets/pusheen.png");
	Sprite *sprite = new Sprite(t);


	
	window->Show();
}

void Application::Run() {
    while (window->isOpen()) {

		this->UpdateDeltaTime();
		OnUpdate();
		OnRender();

    }
}

//event = nullptr;

//component = new MovementComponent(*sprite,0.5,0.25);



//	std::shared_ptr<Texture2D> texture = Texture2D::Create("assets/images/pusheen.png");
//	sprite = new Sprite(1, 1, texture);

	//entity = new Entity::Entity();

	//entity->AddSprite(sprite);

	//entity->AddMovementComponent(component);

//	entity->AddBoxColliderComponent();

	//entity->OnGravity(false);

	//camera = new Camera2D(window->GetWidth() / window->GetHeight());



//	sprite2 = new Sprite(5,5,texture);	



/*if (Collision::Intersects(entity->GetCollider2D(), collider))
	{
		float push = std::min(std::max(1.0f, 0.0f), 1.0f);
		if (entity->GetMovementComponent().GetVelocity().x > 0)
		{
			sprite->Move(-0.1f*push, 0.0f);
		}
		else if(entity->GetMovementComponent().GetVelocity().x < 0)
		{
			sprite->Move(0.1f*push, 0.0f);
		}
		else if(entity->GetMovementComponent().GetVelocity().y > 0)
		{
			sprite->Move(0.0f, -0.1f*push);
		}
		else if(entity->GetMovementComponent().GetVelocity().y < 0)
		{
			sprite->Move(0.0f, 0.1f*push);
		}
	}
	*/


	/*	if(Input::IsKeyPressed(FATON_KEY_T))
		{
			entity->Move(0.0f, 0.1f, float(deltaTime.AsMicroseconds()));
		}
		else if(Input::IsKeyPressed(FATON_KEY_G))
		{
			entity->Move(0.0f, -0.1f, float(deltaTime.AsMicroseconds()));
		}
		else if(Input::IsKeyPressed(FATON_KEY_F))
		{
			entity->Move(-0.1f, 0.0f, float(deltaTime.AsMicroseconds()));
		}
		else if(Input::IsKeyPressed(FATON_KEY_H))
		{
			entity->Move(0.1f, 0.0f, float(deltaTime.AsMicroseconds()));
		}*/