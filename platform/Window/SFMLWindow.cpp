//
// Created by semyon on 03.12.2019.
//

#include "SFMLWindow.h"

SFMLWindow::SFMLWindow(float window_width, float window_height, const char *window_title) {
this->window = new sf::RenderWindow(sf::VideoMode(window_width,window_height),window_title);
this->window->setVerticalSyncEnabled(this->vertical_sync);
this->window->setFramerateLimit(120);

this->width = window_width;
this->height = window_height;
}


void SFMLWindow::Init() {

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

std::unique_ptr<Engine::Window> Engine::Window::Create() {
    return std::unique_ptr<SFMLWindow>();
}

sf::Window &SFMLWindow::GetWindow() const {
    return *this->window;
}



bool SFMLWindow::PollEvent(Engine::Event &event) {
    return false;

}

void SFMLWindow::SetTitle(const char *title) {

}

