//
// Created by semyon on 01.12.2019.
//

#ifndef MY_OWN_GAME_APPLICATION_H
#define MY_OWN_GAME_APPLICATION_H


class Application {
private:
    float winSizeX,winSizeY;

    const char* winTitle;

    sf::RenderWindow * window;

public:
    Application();

    virtual  ~Application();



    void updateDeltaTime();
    void updateEvents();


    void update();
    void render();
    void run();
};


#endif //MY_OWN_GAME_APPLICATION_H
