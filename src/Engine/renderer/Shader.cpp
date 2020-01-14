//
// Created by semyon on 11.12.2019.
//

#include "../../../include/Engine/renderer/Shader.h"
#include "../../../include/Engine/renderer/RendererAPI.h"

#include "../../../platform/OpenGL/OpenGLShader.h"


namespace Engine
{
	std::shared_ptr<Shader> Shader::Create(const char * path_vs, const char * path_fs)
	{
		switch(Engine::RendererAPI::getAPI())
		{
		case RendererAPI::API::NONE: FATON_ERROR_01; return nullptr;
		case RendererAPI::API::SFML:FATON_ERROR_01; return nullptr;
		case RendererAPI::API::OPENGL: return std::make_shared<OpenGLShader>(path_vs,path_fs);
		}
		
		return nullptr;
	}

	std::shared_ptr<Shader> Shader::Create(std::string name, const std::string& vertex_shader_source,
		const std::string fragment_shader_source)
	{
		switch (Engine::RendererAPI::getAPI())
		{
		case RendererAPI::API::NONE: FATON_ERROR_01; return nullptr;
		case RendererAPI::API::SFML:FATON_ERROR_01; return nullptr;
		case RendererAPI::API::OPENGL: return std::make_shared<OpenGLShader>(name,vertex_shader_source,fragment_shader_source);
		}
		return nullptr;
	}
}
