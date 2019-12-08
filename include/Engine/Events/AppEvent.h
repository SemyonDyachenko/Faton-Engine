//
// Created by semyon on 08.12.2019.
//

#ifndef MY_OWN_GAME_APPEVENT_H
#define MY_OWN_GAME_APPEVENT_H


#include "Event.h"

namespace Engine
{
class WindowCloseEvent : public Engine::Event{

        WindowCloseEvent() = default;

        EVENT_CLASS_TYPE(WINDOW_CLOSE)

    };


}


#endif //MY_OWN_GAME_APPEVENT_H
