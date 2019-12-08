//
// Created by semyon on 01.12.2019.
//

#ifndef MY_OWN_GAME_APPLICATION_H
#define MY_OWN_GAME_APPLICATION_H


#include "../../../include/Engine/Core/Window.h"
#include "../../../include/Engine/renderer/Renderer2D.h"
#include <SFML/System.hpp>





class Application {
private:
   Engine::Window* window;
    bool is_run = true;

    Engine::Event* event;


    //time


public:
    Application();
    virtual ~Application();



    void UpdateDeltaTime();




    void Update();
    void Render();
    void Run();
};

Application* CreateApplication();

#endif //MY_OWN_GAME_APPLICATION_H
