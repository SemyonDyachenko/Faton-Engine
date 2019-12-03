//
// Created by semyon on 03.12.2019.
//

#ifndef MY_OWN_GAME_WINDOW_H
#define MY_OWN_GAME_WINDOW_H


namespace Engine {


    class Window {
    public:
        virtual ~Window() = default;

        virtual float GetWidth() const = 0;
        virtual float GetHeight() const = 0;

        virtual void SetVerticalSync(bool enabled) = 0;
        virtual bool IsVerticalSyncEnable() const= 0;


        virtual void Create() = 0;
    };

}


#endif //MY_OWN_GAME_WINDOW_H
