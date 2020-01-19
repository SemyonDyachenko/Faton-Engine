//
// Created by semyon on 01.12.2019.
//


#include "../../../include/SandBox/start/Application.h"


void Application::InitRenderer()
{
	Engine::Renderer2D::Init();


	Engine::RenderCommand::Init();
}

Application::Application() {
	
    this->window = Engine::Window::Create(1280,720,"Engine ");

	
	this->InitRenderer();


	//-----TEST------------


	std::string textureVertexShader = R"(
		#version 330 core

		layout(location = 0) in vec3 position;
		layout(location = 1) in vec2 aTexCoord;

		uniform mat4 ViewProjectionMatrix;
		uniform mat4 Transform;

		out vec2 TexCoord;

		void main()
		{
			
			gl_Position = ViewProjectionMatrix  * Transform * vec4(position,1.0);
			TexCoord = aTexCoord;
		}	


	)";

	std::string textureFragmentShader = R"(
		#version 330 core

		layout(location = 0) out vec4 color;

		in vec2 TexCoord;
	
		uniform sampler2D m_Texture;
		
		uniform vec4 m_Color;
	
		void main()
		 {
			color = texture(m_Texture,TexCoord);
		}


	)";

	m_Texture = Engine::Texture2D::Create("assets/images/photo.jpg");
	
	sprite = new Engine::Sprite(m_Texture);

	m_Camera = new Engine::Camera(window->GetWidth() /window->GetHeight());
	
	m_Shader = Engine::Shader::Create("Shaders/Texture/TextureVertexShader.glsl", "Shaders/Texture/TextureFragmentShader.glsl");

	


	rect = new Engine::Rectangle(0, 0, 2, 2);

	

}

Application::~Application() {
    this->window->Close();
}

void Application::UpdateDeltaTime() {

}


void Application::Update() {


}



void Application::Render() {


	std::shared_ptr<Engine::Texture2D> texture = Engine::Texture2D::Create("assets/images/photo.jpg");



	Engine::Renderer2D::createScene(*m_Camera);
	
	
	
	m_Shader->Bind();

	
	m_Shader->SetMat4("ViewProjectionMatrix", m_Camera->GetViewProjectionMatrix());

	sprite->OnRender();
	
	

	
	
	Engine::Renderer2D::endScene();

	
	

}

void Application::Run() {
    this->event = new Engine::WindowCloseEvent();
    while (this->window->isOpen()) {

		sf::Clock clock;
		float time =float(clock.getElapsedTime().asMicroseconds());
		clock.restart();
		time = time / 800;
    	
    	
        window->PollEvent(*event);
        this->Update();
		this->window->Clear({ 34, 38, 35,1});
    	
        this->Render();

		m_Camera->Update(time);

		
    	
        this->window->Show();

    }
}




