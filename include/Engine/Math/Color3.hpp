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



            T red;
            T green;
            T blue;
            T m_Alpha;

            Color3() {

            }

            Color3(T red,T green,T blue,T m_Alpha) {
                this->red = red;
                this->green = green;
                this->blue = blue;
                this->m_Alpha = m_Alpha;
            }


            inline T GetR() const {
                return this->red;
            }

            inline T GetG() const {
                return this->green;
            }

            inline T GetB() const {
                return this->blue;
            }

            inline void SetR(T red) {
                this->red = red;
            }

            inline void SetG(T green) {
                this->green = green;
            }

            inline void SetB(T blue) {
                this->blue = blue;
            }

            inline void SetAlphaRGB(T m_Alpha) {
                this->m_Alpha = m_Alpha;
            }

        };
    }

}

#endif //MY_OWN_GAME_COLOR3_HPP
