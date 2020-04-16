#ifndef ENGINE_STATE_H
#define ENGINE_STATE_H

#include <stack>

#include "../../../include/Engine/Engine.h"

using namespace Engine;
using namespace Physics;
using namespace Math;

class State
{
public:
	State(std::unique_ptr<Window>&  window, std::stack<State*>* states);

	virtual ~State();

	const bool& GetQuit() const;

	virtual void OnQuit();

	virtual void EndState() = 0;
	virtual void UpdateMousePosition(Camera2D * camera = NULL);
	virtual void UpdateInput(float DeltaTime) = 0;
	virtual void OnUpdate(float DeltaTime) = 0;
	virtual void OnRender(std::unique_ptr<Window> & window) = 0;
	
private:
	std::stack<State*>* m_States;
	std::unique_ptr<Window>* m_Window;

	bool Quit;

	Vec2i m_MousePosScreen;
	Vec2f m_MousePosView;
};


#endif