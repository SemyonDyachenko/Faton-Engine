//
// Created by semyon on 01.12.2019.
//

#include "../../../include/SandBox/start/Application.h"



void Application::InitWindow()
{
	this->Win_Width = 1920;
	this->Win_Height = 1080;
	this->WinTittle = "Planet Saver";
	this->FullScreen = false;
	this->FrameRateLimit = 120;
	this->Vsync = false;
	this->window = Window::Create(static_cast<float>(Win_Width),static_cast<float>(Win_Height), WinTittle);
	this->window->SetFullscreen(FullScreen);
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
	Renderer3D::Init();
	RenderCommand::Init();

	camera = new Camera3D({ 0.0f,0.0f,0.0f }, 70.0f, window->GetWidth() / window->GetHeight(), 0.0f, 1000.f);


	float size = 1.0f;

	std::vector<float> vertices = {   // Green
		-0.5f,0.5f,0,
		-0.5f,-0.5f,0,
		0.5f,-0.5f,0,
		0.5f,0.5f,0,

		-0.5f,0.5f,1,
		-0.5f,-0.5f,1,
		0.5f,-0.5f,1,
		0.5f,0.5f,1,

		0.5f,0.5f,0,
		0.5f,-0.5f,0,
		0.5f,-0.5f,1,
		0.5f,0.5f,1,

		-0.5f,0.5f,0,
		-0.5f,-0.5f,0,
		-0.5f,-0.5f,1,
		-0.5f,0.5f,1,

		-0.5f,0.5f,1,
		-0.5f,0.5f,0,
		0.5f,0.5f,0,
		0.5f,0.5f,1,

		-0.5f,-0.5f,1,
		-0.5f,-0.5f,0,
		0.5f,-0.5f,0,
		0.5f,-0.5f,1,
	};

	std::vector<unsigned int> indices = {
		 0,1,3,   // front face (CCW)
		 3,1,2,  // right face
		 4,5,7,// back face
		 7,5,6,
		8,9,11,
		11,9,10,
		12,13,15,
		15,13,14,
		16,17,19,
		19,17,18,
		20,21,23,
		23,21,22
		// left face
	};

	mesh = new Mesh(vertices, indices);
	texture = Texture2D::Create("assets/images/pusheen.png");

	model = new TexturedModel(mesh, texture);

	entity = new Entity3d(model, { 0,0,0.002f, },0.0f,0.0f,0.0f,1.0f);

}

Application::~Application() {
    this->window->Close();

	

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

	window->Clear({ 0,0,0,1 });


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


