//
// Created by semyon on 04.12.2019.
//

#ifndef MY_OWN_GAME_COLOR3_HPP
#define MY_OWN_GAME_COLOR3_HPP

namespace Engine
{

    namespace Math {
        template<typename T>
        class Color3
        {
        public:
            virtual ~Color3() = default;

            Color3();

            T red;
            T green;
            T blue;
            T m_Alpha;


            Color3(T red,T greeen,T blue,T m_Alpha);

        };
    }

}

#endif //MY_OWN_GAME_COLOR3_HPP
