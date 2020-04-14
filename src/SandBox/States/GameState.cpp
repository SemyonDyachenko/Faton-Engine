#include "../../../include/SandBox/States/GameState.h"

GameState::GameState(std::unique_ptr<Window>& window, std::stack<State*>* states)
	: State(window,states)
{
	m_MainCamera = new Camera2D(window->GetWidth()/window->GetHeight());
	m_MainScene = new Entity::Scene2D(*m_MainCamera);
}

GameState::~GameState()
{
}

void GameState::EndState()
{
	this->OnQuit();
}

void GameState::UpdateInput(float DeltaTime)
{
	
}

void GameState::UpdateMousePosition(Camera2D* camera)
{
}

void GameState::OnUpdate(float DeltaTime)
{
}

void GameState::OnRender(std::unique_ptr<Window>& window)
{
}

