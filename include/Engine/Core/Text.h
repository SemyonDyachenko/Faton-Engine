#ifndef ENGINE_TEXT_H
#define ENGINE_TEXT_H


#include <string>

#include "../Math/Math.h"

#include "Core.h"

namespace Engine
{

	class Text
	{
	public:
		virtual ~Text() = default;
		
		static std::shared_ptr<Text> Create(unsigned int width, unsigned int height);

		virtual void Load(std::string font, unsigned int characterSize) = 0;

		virtual void RenderText(std::string text, float x, float y, float scale, Math::Color3f color = Math::Color3f(255.0,255.0,255.0,1)) = 0;
			
		
	};


}
#endif