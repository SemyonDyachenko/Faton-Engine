//
// Created by semyon on 09.12.2019.
//

#ifndef MY_OWN_GAME_TIMER_H
#define MY_OWN_GAME_TIMER_H


#include <chrono>



namespace Engine {

    class Time
    {

    public:

        ~Time() = default;


        float AsSeconds() {
            return 0.f;
        }

        double AsMicroseconds() {
            return 0.f * 1000000.f;
        }

        double AsMilliseconds() {
            return 0.f * 1000.f;
        }


    };

    class Timer {
        using Clock = std::chrono::high_resolution_clock;


        long lastTime =  std::chrono::duration_cast<std::chrono::nanoseconds>
                (std::chrono::system_clock::now().time_since_epoch()).count();
    public:
        Time GetElapsedTime() {
            return Time();
        }

        Time Restart() {
            return Time();
        }


    };



}


#endif //MY_OWN_GAME_TIMER_H
