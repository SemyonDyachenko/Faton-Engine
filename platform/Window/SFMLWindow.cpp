//
// Created by semyon on 03.12.2019.
//

#include <SFML/Window/Event.hpp>
#include "SFMLWindow.h"
#include "../../include/Engine/Core/Window.h"



void SFMLWindow::Init() {

}

SFMLWindow::SFMLWindow(float window_width, float window_height, const char *window_title) : width(window_width), height(window_height) {
    this->width = window_width;
    this->height = window_height;
    this->title = window_title;
    this->vertical_sync = false;
	this->resizable = false;
    this->fullscreen = false;
    this->frameRateLimit = 120;

    if(!fullscreen) {

        if (this->resizable) {
            this->window = new sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(width), static_cast<unsigned int>(height)), window_title,sf::Style::Default);
        } else {
            this->window = new sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(width),static_cast<unsigned int>(height)), window_title, sf::Style::Close);
        }

    }
    else{
        this->window = new sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(width), static_cast<unsigned int>(height)), window_title, sf::Style::Fullscreen);
    }

    this->window->setVerticalSyncEnabled(this->vertical_sync);
    this->window->setFramerateLimit(this->frameRateLimit);


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



void SFMLWindow::Clear(Engine::Math::Color3<float> color) {
    window->clear(sf::Color(color.red,color.green,color.blue));
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


void *SFMLWindow::GetNativeWindow() const {
    return this->window;
}

void SFMLWindow::SetResizable(bool resizable) {
    this->resizable = resizable;
}

void SFMLWindow::SetFullscreen(bool is_fullscreen) {
this->fullscreen = is_fullscreen;
}

void SFMLWindow::ChangeFrameRateLimit(unsigned int frameRateLimit) {
    this->frameRateLimit = frameRateLimit;
}


void SFMLWindow::Draw(Engine::Sprite &sprite, Engine::Shader &shader) {

}

void SFMLWindow::Draw(Engine::Sprite &sprite) {

}

std::unique_ptr<Engine::Window> Engine::Window::Create(const float width,const float height,const char*title) {
    return  std::make_unique<SFMLWindow>(width,height,title);
}




