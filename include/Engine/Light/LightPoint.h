#ifndef ENGINE_LIGHT_POINT_H
#define ENGINE_LIGHT_POINT_H


#include "../Math/Math.h"

namespace Engine
{

	class LightPoint
	{
	public:
		LightPoint(Engine::Math::Vec2f& positon, Engine::Math::Color3f& colour);

		Engine::Math::Vec2f& GetPosition();

		Engine::Math::Color3f& GetColour();

		void SetPosition(Engine::Math::Vec2f& position);


	private:
		Engine::Math::Vec2f m_Position;
		Engine::Math::Color3f m_Colour;
		Engine::Math::Vec2f attenuation = { 1,0 };
	};

}


#endif