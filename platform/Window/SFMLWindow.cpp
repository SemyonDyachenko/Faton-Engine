//
// Created by semyon on 03.12.2019.
//

#include <SFML/Window/Event.hpp>
#include "SFMLWindow.h"
#include "../SFML/SFMLSprite.h"

void SFMLWindow::Init(float window_width, float window_height, const char *window_title) {
    this->window = new sf::RenderWindow(sf::VideoMode(window_width,window_height),window_title);
    this->window->setVerticalSyncEnabled(this->vertical_sync);
    this->window->setFramerateLimit(120);

    this->width = window_width;
    this->height = window_height;
}


SFMLWindow::SFMLWindow(float window_width, float window_height, const char *window_title) {
this->Init(window_width,window_height,window_title);
}


SFMLWindow::~SFMLWindow() {
delete this->window;
}


float SFMLWindow::GetWidth() const {
    return this->width;
}

float SFMLWindow::GetHeight() const {
    return this->height;
}


void SFMLWindow::SetVerticalSync(bool enabled) {
this->vertical_sync = enabled;
}

bool SFMLWindow::IsVerticalSyncEnable() const {
    return this->vertical_sync;
}




void SFMLWindow::Clear() {
    window->clear();
}

bool SFMLWindow::isOpen() const {
    return window->isOpen();
}


bool SFMLWindow::PollEvent(Engine::Event &event) {
    sf::Event sf_event;

    if(sf_event.type == sf::Event::Closed)
    {
        window->close();
        return 0;
    }
    else {
        return this->window->pollEvent(sf_event);
    }
}

void SFMLWindow::SetTitle(const char *title) {
this->title = title;
}

void SFMLWindow::Show() {
this->window->display();
}

void SFMLWindow::Close() {
this->window->close();
}

void SFMLWindow::Draw(SFMLSprite &sprite){
window->draw(sprite.GetAPISprite());
}

std::unique_ptr<Engine::Window> Engine::Window::Create(float width,float height,const char*title) {
    return   std::make_unique<SFMLWindow>(width,height,title);
}



