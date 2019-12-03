//
// Created by semyon on 03.12.2019.
//

#ifndef MY_OWN_GAME_VECTOR2_HPP
#define MY_OWN_GAME_VECTOR2_HPP

namespace Engine {

    namespace Math {




        template<typename T>
        class Vector2 {
        public:
            //vector 0,0
            Vector2();


            Vector2(T x,T y);


            template<typename F>
            explicit Vector2(const Vector2<F>& vector);

          //  template <typename U>
           // explicit Vector2(const Vector2<U>& vector);


            virtual ~Vector2() = default;

            T x, y; // value x, value y

        };

        template<typename T>
        Vector2<T>::Vector2() {}


        template<typename T>
        Vector2<T>::Vector2(T x, T y) {this->x = x;this->y = y;}


        template<typename T>
        template<typename F>
        Vector2<T>::Vector2(const Vector2<F> &vector){}




    }

}





#endif //MY_OWN_GAME_VECTOR2_HPP
