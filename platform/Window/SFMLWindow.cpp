//
// Created by semyon on 03.12.2019.
//

#include <SFML/Window/Event.hpp>
#include "SFMLWindow.h"
#include "../SFML/SFMLSprite.h"


void SFMLWindow::Init() {

}

SFMLWindow::SFMLWindow(float window_width, float window_height, const char *window_title) {
    this->width = window_width;
    this->height = window_height;
    this->title = window_title;
    this->vertical_sync = false;

    this->window = new sf::RenderWindow(sf::VideoMode(width,height),window_title);
    this->window->setVerticalSyncEnabled(this->vertical_sync);
    this->window->setFramerateLimit(120);

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
    window->clear(sf::Color(150,100,50));
}

bool SFMLWindow::isOpen() const {
    return window->isOpen();
}


bool SFMLWindow::PollEvent(Engine::Event &event) {
    sf::Event sf_event;

    while(window->pollEvent(sf_event)) {
        if (sf_event.type == sf::Event::Closed) {
            window->close();
        }
    }
    return this->window->pollEvent(sf_event);

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
//window->draw(sprite.GetAPISprite());
}

void *SFMLWindow::GetNativeWindow() const {
    return this->window;
}


 std::unique_ptr<Engine::Window> Engine::Window::Create(const float width,const float height,const char*title) {
    return  std::make_unique<SFMLWindow>(width,height,title);
}



