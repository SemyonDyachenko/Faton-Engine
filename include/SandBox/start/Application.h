//
// Created by semyon on 01.12.2019.
//

#ifndef MY_OWN_GAME_APPLICATION_H
#define MY_OWN_GAME_APPLICATION_H


#include "../../../include/Engine/Engine.h"




class Application {
private:
    std::unique_ptr<Engine::Window> window;


	std::shared_ptr<Engine::Shader> m_Shader;

	Engine::Math::Vec4f m_Color =  { 0.2f, 0.3f, 0.8f, 1.0f };
	
    Engine::Event* event{};


    bool is_Running = true;

	void InitRenderer();
public:
    Application();
    virtual ~Application();


	
    void Update();
    void Render();
    void Run();
};


#endif //MY_OWN_GAME_APPLICATION_H
