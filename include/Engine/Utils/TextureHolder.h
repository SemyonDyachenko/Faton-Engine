#ifndef ENGINE_TEXTURE_HOLDER
#define ENGINE_TEXTURE_HOLDER


#include <map>
#include "../renderer/Texture.h"
#include <string>

namespace Engine
{


	namespace Textures
	{
		enum TextureID
		{

		};
	}


	namespace Utils
	{


		class TextureHolder
		{
		public:
			void Load(Textures::TextureID id, const std::string& filename);

			const std::shared_ptr<Texture2D>& Get(Textures::TextureID id) const;

		private:
			std::map<Textures::TextureID, std::shared_ptr<Texture2D>> m_TextureMap;

		};

	}


}




#endif