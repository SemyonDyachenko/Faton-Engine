//
// Created by semyon on 16.12.2019.
//

#include "OpenGLShader.h"
#include "../../include/Engine/Core/Core.h"
#include <glm/gtc/type_ptr.hpp>




std::string OpenGLShader::LoadShader(const std::string& filename)
{
	std::ifstream file;
	file.open((filename).c_str());

	std::string out;
	std::string line;

	

	
	if (file.is_open())
	{
		while (file.good())
		{
			std::getline(file, line);
			out.append(line + "\n");
		}
	}
	else
	{
		std::cerr << "Error to load Shader: " << filename << std::endl;
	}

	return out;
	
}

GLuint OpenGLShader::CreateShader(const std::string text, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	if(shader == NULL)
	{
		std::cout << "Error:Shader creation failed" << std::endl;
	}

	const GLchar* shaderSourceStrings[1];
	GLint shaderSourceStringLength[1];
	shaderSourceStringLength[0] = text.length();
	shaderSourceStrings[0] = text.c_str();

	glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLength);
	glCompileShader(shader);


	return shader;
}


OpenGLShader::OpenGLShader(const std::string& path_vs, const std::string& path_fs)
{
	this->programID = glCreateProgram();

	shaders[0] = CreateShader(LoadShader(path_vs), GL_VERTEX_SHADER);
	shaders[1] = CreateShader(LoadShader(path_fs), GL_FRAGMENT_SHADER);


	for(int i= 0;i < NUMBER_OF_SHADER;i++)
	{
		glAttachShader(programID, shaders[i]);
	}

	glLinkProgram(this->programID);
	glValidateProgram(this->programID);
}

OpenGLShader::OpenGLShader(std::string name, const std::string& vertex_shader_source,
	const std::string& fragment_shader_source)
{
	this->programID = glCreateProgram();


	this->name = name;
	
	shaders[0] = CreateShader(vertex_shader_source, GL_VERTEX_SHADER);
	shaders[1] = CreateShader(fragment_shader_source, GL_FRAGMENT_SHADER);

	for (int i = 0; i < NUMBER_OF_SHADER; i++)
	{
		glAttachShader(programID, shaders[i]);
	}

	glLinkProgram(this->programID);
	glValidateProgram(this->programID);
}


OpenGLShader::~OpenGLShader()
{
	glDeleteProgram(this->programID);
}

void OpenGLShader::SetInt(const char* name, int value)
{
	GLint location = glGetUniformLocation(programID, name);
	glUniform1i(location, value);
}

void OpenGLShader::SetFloat(const char* name,float value)
{
	GLint location = glGetUniformLocation(programID, name);
	glUniform1f(location, value);
}

void OpenGLShader::SetFloat2(const char* name, const Engine::Math::Vec2f& value)
{
	GLint location = glGetUniformLocation(programID, name);
	glUniform2f(location, value.x, value.y);
}

void OpenGLShader::SetFloat3(const char * name, const Engine::Math::Vec3f & value)
{
	GLint location = glGetUniformLocation(programID, name);
	glUniform3f(location, value.x,value.y,value.z);
}

void OpenGLShader::SetFloat4(const char* name, const Engine::Math::Vec4f& value)
{
	GLint location = glGetUniformLocation(programID, name);
	glUniform4f(location, value.x, value.y, value.z,value.w);
}

void OpenGLShader::SetMat3(const char * name, const glm::mat3 & value)
{
	GLint location = glGetUniformLocation(programID, name);
	glUniformMatrix3fv(location,1,GL_FALSE,glm::value_ptr(value));
}


void OpenGLShader::SetMat4(const char* name, const glm::mat4& value)
{
	GLint location = glGetUniformLocation(programID, name);
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

std::string OpenGLShader::GetName() const
{
	return this->name;
}

void OpenGLShader::Bind()
{
	glUseProgram(this->programID);
}

void OpenGLShader::Unbind()
{
	glUseProgram(0);
}
