#include "../../../include/SandBox/States/State.h"

State::State(std::unique_ptr<Window>& window, std::stack<State*>* states)
{
	m_Window = &window;
	Quit = false;
	m_States = states;
}

State::~State()
{
}

const bool& State::GetQuit() const
{
	return Quit;
}

void State::OnQuit()
{
	if(!Quit)
	{
		Quit = true;
	}
}


void State::UpdateMousePosition(Camera2D* camera)
{
	this->m_MousePosScreen.x = int(Input::GetMousePositionX());
	this->m_MousePosScreen.y = int(Input::GetMousePositionY());
};
	
