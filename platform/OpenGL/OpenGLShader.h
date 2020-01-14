//
// Created by semyon on 16.12.2019.
//

#ifndef MY_OWN_GAME_OPENGLSHADER_H
#define MY_OWN_GAME_OPENGLSHADER_H

#include "../../include/Engine/renderer/Shader.h"

#include <GL/glew.h>

#include <iostream>
#include <string>
#include <fstream>


static GLenum ShaderTypeToOpenGLType(Engine::ShaderType type)
{
	switch(type)
	{
		case Engine::ShaderType::Float: return GL_FLOAT;
		case Engine::ShaderType::Float2: return GL_FLOAT;
		case Engine::ShaderType::Float3: return GL_FLOAT;
		case Engine::ShaderType::Float4: return GL_FLOAT;
		case Engine::ShaderType::Mat3: return GL_FLOAT;
		case Engine::ShaderType::Mat4: return GL_FLOAT;
		case Engine::ShaderType::Int: return GL_INT;
		case Engine::ShaderType::Int2:return GL_INT;
		case Engine::ShaderType::Int3:return GL_INT;
		case Engine::ShaderType::Int4: return GL_INT;
		case Engine::ShaderType::Bool: return GL_BOOL;
	}
}

class OpenGLShader : public Engine::Shader {

public:
	OpenGLShader(const std::string& path_vs, const std::string& path_fs);
	OpenGLShader(std::string name,const std::string& vertex_shader_source, const std::string& fragment_shader_source);
	virtual ~OpenGLShader();

	void SetInt(const char* name, int value) override;
	void SetFloat(const char* name, float value) override;
	void SetFloat2(const char* name, const Engine::Math::Vec2f& value) override;
	void SetFloat3(const char* name, const Engine::Math::Vec3f& value) override;
	void SetFloat4(const char* name, const Engine::Math::Vec4f& value) override;
	void SetMat3(const char* name, const glm::mat3& value) override;
	void SetMat4(const char* name, const glm::mat4& value) override;

	std::string GetName() const override;
	
	void Bind() override;

	void Unbind() override;
private:
	std::string LoadShader(const std::string & filename);

	GLuint CreateShader(const std::string text,GLenum shaderType);
private:
	static const unsigned int NUMBER_OF_SHADER = 2;
	GLuint shaders[NUMBER_OF_SHADER];
	unsigned int programID;
	std::string  name;
	
};


#endif //MY_OWN_GAME_OPENGLSHADER_H
