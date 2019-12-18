//
// Created by semyon on 18.12.2019.
//

#ifndef MY_OWN_GAME_MATH_H
#define MY_OWN_GAME_MATH_H




namespace Engine
{
    namespace Math
    {
        static double PI = 3.14159265;

        class Math
        {
        public:

            static double to_radians(const double& degrees)
            {
                return static_cast<double>(degrees*(PI/180));
            }

            static float to_degrees(const double& radians)
            {
                return static_cast<float>(radians*(180/PI));
            }

        };
    }
}


#endif //MY_OWN_GAME_MATH_H
