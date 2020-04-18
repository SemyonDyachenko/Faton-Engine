#include "../../../include/Engine/Light/LightPoint.h"

Engine::LightPoint::LightPoint(Engine::Math::Vec2f& positon, Engine::Math::Color3f& colour)
{
	lightShader = Shader::Create("Shaders/Light/LightVertexShader.glsl", "Shaders/Light/LightFragmentShader.glsl");
	
		
}

Engine::Math::Vec2f& Engine::LightPoint::GetPosition()
{
	return m_Position;
}

Engine::Math::Color3f& Engine::LightPoint::GetColour()
{
	return m_Colour;
}

void Engine::LightPoint::SetPosition(Engine::Math::Vec2f& position)
{
	m_Position = position;
}

void Engine::LightPoint::OnRender(Camera2D& camera)
{
	lightShader->Bind();

}
