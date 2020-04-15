#include "..\..\..\include\Engine\Utils\TextureHolder.h"

namespace Engine
{

	namespace Utils
	{

		void TextureHolder::Load(Textures::TextureID id, const std::string& filename)
		{
			std::shared_ptr<Texture2D> texture = Texture2D::Create(filename.c_str());

			m_TextureMap.insert(std::make_pair(id, std::move(texture)));
		}

		const std::shared_ptr<Texture2D>& Engine::Utils::TextureHolder::Get(Textures::TextureID id) const
		{
			auto found = m_TextureMap.find(id);
			return found->second;
		}

	}
}