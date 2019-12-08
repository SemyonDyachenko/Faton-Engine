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


#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }



    class Event {

    public:
        bool EventHandled = false;

        virtual EventType GetEventType() = 0;
        virtual const char* GetName() = 0;



        EventType type;



        virtual ~Event() = default;
    };
}



#endif //MY_OWN_GAME_EVENT_H
