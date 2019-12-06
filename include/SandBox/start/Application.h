//
// Created by semyon on 01.12.2019.
//

#ifndef MY_OWN_GAME_APPLICATION_H
#define MY_OWN_GAME_APPLICATION_H


#include "../../../include/Engine/Core/Window.h"

class Application {
private:
    Engine::Window * window;
    bool is_run = true;


public:
    Application();
    virtual ~Application();


    void Update();
    void Render();
    void Run();
};


#endif //MY_OWN_GAME_APPLICATION_H