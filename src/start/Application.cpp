//
// Created by semyon on 01.12.2019.
//

#include "Application.h"


void Application::init_states() {
    this->states.push(new MainMenuState(this->window,&this->states));
}

void Application::init_window() {
this->win_size_x = 1440;
this->win_size_y= 900;
this->vertical_sync_enable = false;
this->frame_rate_limit = 120;

this->win_title = "From The Darkness Of Night";

this->window = new sf::RenderWindow(sf::VideoMode(this->win_size_x,this->win_size_y),this->win_title);
this->window->setFramerateLimit(this->frame_rate_limit);

}


Application::Application() {
this->init_window();
this->init_states();

}

Application::~Application() {
delete this->window;
}

void Application::updateDeltaTime() {
this->delta_time = clock.restart().asSeconds();
}

void Application::updateEvents() {
while(this->window->pollEvent(this->main_event))
{
    if(this->main_event.type == sf::Event::Closed)
        this->window->close();
}

}

void Application::update() {
this->updateEvents();


}

void Application::render() {
this->window->clear();
this->window->display();
}

void Application::run() {
while(this->window->isOpen())
{
    this->updateDeltaTime();
    this->update();
    this->render();
}
}

