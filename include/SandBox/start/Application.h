//
// Created by semyon on 01.12.2019.
//

#ifndef MY_OWN_GAME_APPLICATION_H
#define MY_OWN_GAME_APPLICATION_H


#include "../../../include/Engine/Engine.h"




class Application {
private:
    std::unique_ptr<Engine::Window> window;

	Engine::Sprite * sprite;

	Engine::Camera* m_Camera;
	std::shared_ptr<Engine::Texture2D> m_Texture;
	std::shared_ptr<Engine::Shader> m_Shader;
	Engine::Rectangle * rect;

	Engine::Math::Vec4f m_Color =  { 0.2f, 0.3f, 0.8f, 1.0f };
	
    Engine::Event* event;



    bool running = true;

    //time
    float lastFrameTime;


	void InitRenderer();
public:
    Application();
    virtual ~Application();



    void UpdateDeltaTime();


	
    void Update();
    void Render();
    void Run();
};


#endif //MY_OWN_GAME_APPLICATION_H
