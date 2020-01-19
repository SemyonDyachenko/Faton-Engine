#ifndef ENGINE_RECT_HPP
#define ENGINE_RECT_HPP


namespace Engine
{
	namespace Math
	{
		template<typename T>
		class Rect
		{
		public:
			
			Rect();

			Rect(T x, T y, T w, T h);

			template<typename F>
			explicit Rect(const Rect<F>& vector);

			virtual ~Rect() = default;
			
			T x, y, w, h;

			
		};

		template <typename T>
		Rect<T>::Rect()
		{
		}

		template <typename T>
		Rect<T>::Rect(T x, T y, T w, T h)
		{
			this->x = x;
			this->y = y;
			this->w = w;
			this->h = h;
		}

		template <typename T>
		template <typename F>
		Rect<T>::Rect(const Rect<F>& vector)
		{
			this->x = vector.x;
			this->y = vector.y;
			this->w = vector.w;
			this->h = vector.h;
		}

		typedef Rect<float> FloatRect;
		typedef Rect<int> IntRect;
	}
	
}


#endif