//
// Created by semyon on 11.12.2019.
//

#ifndef MY_OWN_GAME_SHADER_H
#define MY_OWN_GAME_SHADER_H

#include <memory>
#include <string>
#include <glm/glm.hpp>
#include "../Math/Math.h"

namespace Engine {

	enum class ShaderType
	{
		Float,
		Float2,
		Float3,
		Float4,
		Mat3,
		Mat4,
		Int,
		Int2,
		Int3,
		Int4,
		Bool
		
	};
	
    class Shader
	{
    public:
        virtual ~Shader() = default;

        virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void SetInt(const char* name, int value) = 0;
		virtual void SetFloat(const char* name,float value) = 0;
		virtual void SetFloat2(const char* name,const Math::Vec2f& value) = 0;
		virtual void SetFloat3(const char* name,const Math::Vec3f& value) = 0;
		virtual void SetFloat4(const char* name, const Math::Vec4f&  value) = 0;
		virtual void SetMat3(const char* name, const glm::mat3& value) = 0;
		virtual void SetMat4(const char* name, const glm::mat4& value) = 0;
    	
		virtual std::string GetName() const =  0;

    	
        static std::shared_ptr<Shader> Create(const char* path_vs,const char* path_fs);

		static std::shared_ptr<Shader> Create(std::string name,const std::string& vertex_shader_source, const std::string fragment_shader_source);
    };


	class ShaderLibrary
	{
		
	};

}

#endif //MY_OWN_GAME_SHADER_H
