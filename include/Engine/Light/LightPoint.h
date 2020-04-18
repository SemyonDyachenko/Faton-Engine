#ifndef ENGINE_LIGHT_POINT_H
#define ENGINE_LIGHT_POINT_H


#include "../Math/Math.h"
#include "../renderer/Shader.h"
#include "../Camera/Camera.h"

namespace Engine
{

	class LightPoint
	{
	public:
		LightPoint(Math::Vec2f& positon, Math::Color3f& colour);

		Engine::Math::Vec2f& GetPosition();

		Engine::Math::Color3f& GetColour();

		void SetPosition(Engine::Math::Vec2f& position);


		void OnRender(Camera2D& camera);
	private:
		Math::Vec2f m_Position;
		Math::Color3f m_Colour;
		Math::Vec2f attenuation = { 1,0 };

		std::shared_ptr<Shader> lightShader;
	};

}


#endif