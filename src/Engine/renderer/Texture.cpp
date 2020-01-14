#include "../../../include/Engine/renderer/Texture.h"
#include "../../../include/Engine/renderer/RendererAPI.h"
#include "../../../platform/OpenGL/OpenGLTexture.h"

namespace Engine
{

	std::shared_ptr<Texture2D> Texture2D::Create(const char * path)
	{
		switch(RendererAPI::getAPI())
		{
			case RendererAPI::API::NONE: FATON_ERROR_01; return nullptr;
			case RendererAPI::API::SFML: FATON_ERROR_01; return nullptr;
			case RendererAPI::API::OPENGL: return std::make_shared<OpenGLTexture>(path);
		}

		return nullptr;
	}
	
}
