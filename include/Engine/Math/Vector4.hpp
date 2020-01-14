//
// Created by semyon on 5.1.2020.
//

#ifndef MY_OWN_GAME_VECTOR4_H
#define MY_OWN_GAME_VECTOR4_H

namespace Engine {

	namespace Math {

		template<typename T>
		class Vector4 {
		public:
			//default constructor with value (0,0,0,0)
			Vector4();

			Vector4(T x, T y, T z,T w);

			virtual ~Vector4() = default;



			template <typename F>
			explicit Vector4(const Vector4<F>& vector);


			T x, y, z, w;

		};

		template<typename T>
		Vector4<T>::Vector4() {}



		template<typename T>
		Vector4<T>::Vector4(T x, T y, T z,T w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;

		}

		template<typename T>
		template<typename F>
		Vector4<T>::Vector4(const Vector4<F> &vector) {

		}

		typedef Math::Vector4<float> Vec4f;
		typedef Math::Vector4<int> Vec4i;
		typedef Math::Vector4<unsigned int> vec4u;

	}



}




#endif //MY_OWN_GAME_VECTOR3_H
