//
// Created by semyon on 01.12.2019.
//

#ifndef MY_OWN_GAME_APPLICATION_H
#define MY_OWN_GAME_APPLICATION_H

#include <SFML/Graphics.hpp>



class Application {
private:
    //std::stack<State*> states;

    float win_size_x,win_size_y;
    std::vector<sf::VideoMode> video_modes;
    bool vertical_sync_enable;
    unsigned int frame_rate_limit;
    const char* win_title;

    sf::RenderWindow *window;

    sf::Event main_event;
    sf::Clock clock;
    float delta_time;


    void init_window();
    void init_states();
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
