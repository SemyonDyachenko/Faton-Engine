//
// Created by semyon on 01.12.2019.
//

#include "../../../include/SandBox/start/Application.h"





void Application::InitWindow()
{
	this->Win_Width = 1440;
	this->Win_Height = 900;
	this->WinTittle = "Banana Sandbox";
	this->FullScreen = false;
	this->FrameRateLimit = 120;
	this->Vsync = false;
	this->window = Window::Create(static_cast<float>(Win_Width),static_cast<float>(Win_Height), WinTittle);
	this->window->SetVerticalSync(Vsync);
	this->window->SetResizable(false);
	this->window->ChangeFrameRateLimit(FrameRateLimit);

}

void Application::InitStates()
{
	//this->states.push(new GameState(window,&states));
}

Application::Application() {
	this->InitWindow();
	this->InitStates();
	Renderer2D::Init();
	Renderer3D::Init();
	RenderCommand::Init();

	camera = new Camera3D(window->GetWidth() / window->GetHeight());



	float size = 0.5f;

	std::vector<float> vertices = {
		1,1,-1,
		1,-1,-1,
		1,1,1,
		1,-1,1,
		-1,1,-1,
		-1,-1,-1,
		-1,1,1,
		-1,-1,1

	};


	std::vector<unsigned int> indices = {
				1,1,1,5,2,1,7,3,1,3,4,1,
				4,5,2,3,6,2,7,7,2,8,8,2,
				8,8,3,7,7,3,5,9,3,6,10,3,
				6,10,4,2,11,4,4,12,4,8,13,4,
				2,14,5,1,15,5,3,16,5,4,17,5,
				6,18,6,5,19,6,1,20,6,2,11,6
	};

	mesh = new Mesh(vertices, indices);
	texture = Texture2D::Create("assets/images/pusheen.png");

	model = new TexturedModel(mesh, texture);

	entity = new Entity3d(model, { 0,0,-0.1f, }, 0.0f, 0.0f, 0.0f, 1.0f);


}

Application::~Application() {
    this->window->Close();

	

}

void Application::UpdateDeltaTime()
{
	float time = (float)glfwGetTime();
	deltaTime = new Time(float(time - LastFrameTime) / 1000);
	LastFrameTime = time;

	camera->OnUpdate(deltaTime->AsMicroseconds());


	camera->MouseHandle(Engine::Input::GetMousePosition().x,Engine::Input::GetMousePosition().y,window);
	
}


void Application::OnUpdate() {
	
	window->PollEvent(*event);




} 




void Application::OnRender() {

	window->Clear({ 138, 221, 237,1 });


	entity->OnRender(*camera);


	
	window->Show();
}

void Application::Run() {
    while (window->isOpen()) {  

		this->UpdateDeltaTime();
		OnUpdate();
		OnRender();
		

    }
}


