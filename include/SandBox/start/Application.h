//
// Created by semyon on 01.12.2019.
//

#ifndef MY_OWN_GAME_APPLICATION_H
#define MY_OWN_GAME_APPLICATION_H


#include "../../../include/Engine/Engine.h"
#include "../../../include/Engine/Entity/Entity.h"
#include <GLFW/glfw3.h>

#include "../States/State.h"

using namespace Engine;
using namespace Math;
using namespace Physics;


class Application {
private:
	unsigned int Win_Width, Win_Height;
	unsigned int FrameRateLimit;
	bool FullScreen;
	bool Vsync;
	std::string WinTittle;
    std::unique_ptr<Window> window;
	std::stack<State*> states;
	
	Event *event;

    bool IsRunning = true;
	Time *deltaTime;
	float LastFrameTime;
	
	void InitAPI();
	void InitWindow();
	void InitStates();

	std::shared_ptr<Texture2D> texture;
	Camera2D * camera;
	Sprite *sprite;
public:
    Application();
    virtual ~Application();


	void UpdateDeltaTime();
	
    void OnUpdate();
	
    void OnRender();

    void Run();
};


#endif //MY_OWN_GAME_APPLICATION_H
