//
// Created by semyon on 08.12.2019.
//

#include <string>
#include "../../../include/Engine/Events/AppEvent.h"

Engine::EventType Engine::WindowCloseEvent::GetEventType() {
    return EventType::WINDOW_CLOSE;
}

const char *Engine::WindowCloseEvent::GetName() {
    return "WINDOW_CLOSE";

}
