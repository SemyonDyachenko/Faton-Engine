//
// Created by semyon on 03.12.2019.
//

#ifndef MY_OWN_GAME_WINDOW_H
#define MY_OWN_GAME_WINDOW_H

#include "../Events/Event.h"
#include "../renderer/Sprite.h"
#include "Core.h"

#include <memory>


namespace Engine {


    class Window {
    public:
        virtual ~Window() = default;

        virtual float GetWidth() const = 0;
        virtual float GetHeight() const = 0;

        virtual void SetVerticalSync(bool enabled) = 0;
        virtual bool IsVerticalSyncEnable() const= 0;

        virtual void SetResizable(bool resizable) = 0;

        virtual void SetFullscreen(bool is_fullscreen) = 0;

        virtual void ChangeFrameRateLimit(unsigned int frameRateLimit) = 0;

        virtual void Clear(Math::Color3<float> color) = 0;

        //virtual void Update() = 0;


        virtual bool PollEvent(Event& event) = 0;

        virtual void SetTitle(const char * title) = 0;


        virtual bool isOpen() const = 0;


        virtual void Close() =  0;


        virtual void Draw(Sprite & sprite) = 0;

         static std::unique_ptr<Window> Create(const float width,const float height,const char*title);


        virtual void Show() = 0;
    };

}


#endif //MY_OWN_GAME_WINDOW_H
