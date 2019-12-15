//
// Created by semyon on 09.12.2019.
//

#ifndef MY_OWN_GAME_TIMER_H
#define MY_OWN_GAME_TIMER_H


#include <chrono>



namespace Engine {

    class Time
    {
    private:
        float time;
    public:
        Time(float time) : time(time)
        {

        }

        ~Time() = default;


        float AsSeconds() {
            return time;
        }

        double AsMicroseconds() {
            return time * 1000000.f;
        }

        double AsMilliseconds() {
            return time * 1000.f;
        }


    };


    };


#endif //MY_OWN_GAME_TIMER_H
