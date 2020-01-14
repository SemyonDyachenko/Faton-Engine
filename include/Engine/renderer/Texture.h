#ifndef ENGINE_TEXTURE_H

#define ENGINE_TEXTURE_H
#include "../Math/Vector2.hpp"
#include <memory>


namespace Engine
{

	class Texture2D
	{
	public:
		virtual ~Texture2D() = default;

		virtual Math::Vec2f GetSize() const = 0;

		virtual void Bind(unsigned int slot = 0) const = 0;

		static std::shared_ptr<Texture2D> Create(const char * path);

	private:
	};
	
	
}





#endif