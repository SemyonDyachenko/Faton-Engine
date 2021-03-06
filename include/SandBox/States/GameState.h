
#ifndef ENGINE_GAME_STATE_H
#define ENGINE_GAME_STATE_H


#include "State.h"
#include "../GameObjects/GameWorld.h"


class GameState : public State
{
public:
	GameState(std::unique_ptr<Window>& window,std::stack<State*>* states);
	virtual ~GameState();

	void EndState() override;
	void UpdateInput(float DeltaTime) override;
	void UpdateMousePosition(Camera2D* camera) override;
	void OnUpdate(float DeltaTime) override;
	void OnRender(std::unique_ptr<Window>& window) override;
private:
	GameWorld * m_World;
};


#endif