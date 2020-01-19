//
// Created by semyon on 07.12.2019.
//

#ifndef MY_OWN_GAME_VECTOR3_H
#define MY_OWN_GAME_VECTOR3_H

namespace Engine {

    namespace Math {

        template<typename T>
        class Vector3 {
        public:
            //default constructor with value (0,0,0)
            Vector3();

            Vector3(T x,T y,T z);

            virtual ~Vector3() = default;

           

            template <typename F>
            explicit Vector3(const Vector3<F>& vector);


			T x, y, z;

        };

        template<typename T>
		Vector3<T>::Vector3() {}

        

        template<typename T>
        Vector3<T>::Vector3(T x, T y, T z) {
            this->x = x;
            this->y = y;
            this->z = z;

        }

        template<typename T>
        template<typename F>
        Vector3<T>::Vector3(const Vector3<F> &vector) {
			this->x = vector.x;
			this->y = vector.y;
			this->z = vector.z;
        }

		typedef Vector3<float> Vec3f;
		typedef Vector3<int> Vec3i;
		typedef Vector3<unsigned int> vec3u;

    }



}




#endif //MY_OWN_GAME_VECTOR3_H
