#include "../../../include/SandBox/States/GameState.h"

GameState::GameState(std::unique_ptr<Window>& window, std::stack<State*>* states)
	: State(window,states)
{
	m_World = new GameWorld();
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
	m_World->Update(DeltaTime);
}

void GameState::OnRender(std::unique_ptr<Window>& window)
{
	m_World->Render();
}

