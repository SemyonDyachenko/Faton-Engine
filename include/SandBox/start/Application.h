//
// Created by semyon on 01.12.2019.
//

#ifndef MY_OWN_GAME_APPLICATION_H
#define MY_OWN_GAME_APPLICATION_H


#include "../../../include/Engine/Engine.h"
#include <SFML/System.hpp>





class Application {
private:
    std::unique_ptr<Engine::Window> window;


    Engine::Event* event;


    bool running = true;

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
