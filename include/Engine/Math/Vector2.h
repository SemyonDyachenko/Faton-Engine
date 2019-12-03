//
// Created by semyon on 03.12.2019.
//

#ifndef MY_OWN_GAME_VECTOR2_H
#define MY_OWN_GAME_VECTOR2_H

namespace Engine {

    namespace Math {

        template<typename T>
        class Vector2 {
        public:
            T x, y; // value x, value y




            //vector 0,0
            Vector2();


            Vector2(T x,T y);



            template<typename F>
            explicit Vector2(const Vector2<F>& vector);

            template <typename U>
            explicit Vector2(const Vector2<U>& vector);


            ~Vector2();


        };
    }

}

#endif //MY_OWN_GAME_VECTOR2_H
