#ifndef ENGINE_TEXT_H
#define ENGINE_TEXT_H


#include <string>

#include "../Math/Math.h"

#include <glm/glm.hpp>

#include "../Camera/Camera.h"

#include "Core.h"

namespace Engine
{

	class Text
	{
	public:
		virtual ~Text() = default;
		
		static std::unique_ptr<Text> Create(unsigned int width, unsigned int height);

		virtual void Load(std::string font, unsigned int characterSize) = 0;

		virtual void IsStatic(bool staticVal) = 0;

		virtual void RenderText(const glm::mat4& projection,std::string text, float x, float y, float scale, glm::vec3 color = glm::vec3(1.0f)) = 0;
			
		
	};


}
#endif