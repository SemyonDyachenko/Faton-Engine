#ifndef ENGINE_TEXTURE_HOLDER_H
#define ENGINE_TEXTURE_HOLDER_H

#include <vector>
#include <memory>
#include "Texture.h"


namespace Engine
{

	class TextureHolder
	{
	private:
		static std::vector<std::shared_ptr<Texture2D>> m_Textures;

	public:
		
		
		static std::shared_ptr<Texture2D> Add(std::shared_ptr<Texture2D> texture);

		static std::shared_ptr<Texture2D> Get(const std::string& name);

		static void Clean();
	};
}





#endif