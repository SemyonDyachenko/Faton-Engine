//
// Created by semyon on 04.12.2019.
//

#ifndef MY_OWN_GAME_EVENT_H
#define MY_OWN_GAME_EVENT_H

namespace Engine
{
    enum class EventType
    {
     NONE = 0,
     WINDOW_CLOSE = 0,
     KEY_PRESSED,
     KEY_RELEASED,
     MOUSE_BUTTON_PRESSED,
     MOUSE_BUTTON_RELEASED,
     MOUSE_SCROLL
    };

    class Event {

    public:
        virtual ~Event() = default;
    };
}



#endif //MY_OWN_GAME_EVENT_H
