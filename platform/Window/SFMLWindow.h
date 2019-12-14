//
// Created by semyon on 03.12.2019.
//

#ifndef MY_OWN_GAME_SFMLWINDOW_H
#define MY_OWN_GAME_SFMLWINDOW_H


#include <SFML/Graphics/RenderWindow.hpp>

#include "../../include/Engine/Events/Event.h"
#include "../../include/Engine/Core/Window.h"
#include "../SFML/SFMLSprite.h"


#include <memory>


class SFMLWindow : public Engine::Window {
private:
    sf::RenderWindow * window;

    const char* title;
    float width,height;
    unsigned int frameRateLimit;

    bool vertical_sync;
    bool resizable;
    bool fullscreen;

    void Init();
public:
    SFMLWindow(float window_width,float window_height,const char * window_title);

    virtual ~SFMLWindow();

    void Clear(Engine::Math::Color3<float> color) override;

     float GetWidth() const override;
     float GetHeight() const override;

    void SetVerticalSync(bool enabled) override;
    bool IsVerticalSyncEnable() const override;

    void ChangeFrameRateLimit(unsigned int frameRateLimit) override;

    void SetFullscreen(bool is_fullscreen) override;

    void SetResizable(bool resizable) override;

    inline virtual void* GetNativeWindow() const;

    bool PollEvent(Engine::Event & event) override;


    bool isOpen() const override;

    void Close() override;

    void SetTitle(const char * title) override;

    void Show() override;


};


#endif //MY_OWN_GAME_SFMLWINDOW_H
