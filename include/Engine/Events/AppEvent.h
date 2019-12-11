//
// Created by semyon on 08.12.2019.
//

#ifndef MY_OWN_GAME_APPEVENT_H
#define MY_OWN_GAME_APPEVENT_H


#include "Event.h"

namespace Engine
{
class WindowCloseEvent : public Engine::Event{
public:
        WindowCloseEvent() = default;


        EventType GetEventType() override;

        const char* GetName() override;
};


}


#endif //MY_OWN_GAME_APPEVENT_H
