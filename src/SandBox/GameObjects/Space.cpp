#include "..\..\..\include\SandBox\GameObjects\Space.h"



SpaceArea::SpaceArea(float aspectRatio, float rocketX, float rocketY)
{
	m_Camera = new Engine::Camera2D(aspectRatio);

	m_RocketCharacter = new RocketMainCharacter(rocketX,rocketY);

	m_RocketSpriteComponent = new Engine::Sprite(m_RocketCharacter->GetPosition().x, m_RocketCharacter->GetPosition().y);

	m_RocketCharacter->AddSpriteComponent(m_RocketSpriteComponent);
}

SpaceArea::~SpaceArea()
{

}

void SpaceArea::Update(float DeltaTime)
{
	m_RocketCharacter->OnUpdate(DeltaTime);
}

void SpaceArea::Render()
{
	m_RocketCharacter->OnRender(*m_Camera);
}
