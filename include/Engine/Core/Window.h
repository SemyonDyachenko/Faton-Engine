//
// Created by semyon on 03.12.2019.
//

#ifndef MY_OWN_GAME_WINDOW_H
#define MY_OWN_GAME_WINDOW_H

#include "Event.h"
#include <memory>



namespace Engine {


    class Window {
    public:
        virtual ~Window() = default;

        virtual float GetWidth() const = 0;
        virtual float GetHeight() const = 0;

        virtual void SetVerticalSync(bool enabled) = 0;
        virtual bool IsVerticalSyncEnable() const= 0;

        virtual void Clear(float red = 0,float green = 0,float blue = 0,float alpha =0) = 0;

        //virtual void Update() = 0;

        virtual bool PollEvent(Event& event) = 0;

        virtual void SetTitle(const char * title) = 0;


        virtual bool isOpen() const = 0;


        virtual std::unique_ptr<Window> Create();
    };

}


#endif //MY_OWN_GAME_WINDOW_H
