#include "../../../include/Engine/renderer/Drawable2D.h"
#include "../../../include/Engine/renderer/Renderer2D.h"

Engine::Drawable2D::Drawable2D(const Math::Vec2f & position, const Math::Vec2f & size) : m_Visible(true),m_Texture(nullptr),bounds(position.x,position.y,size.x,size.y)
{


}

Engine::Drawable2D::~Drawable2D()
{
}



const Engine::Math::Vec2f& Engine::Drawable2D::GetPosition() const
{
	return Math::Vec2f(bounds.x, bounds.y);
}

const Engine::Math::Vec2f& Engine::Drawable2D::GetSize() const
{
	return Math::Vec2f(bounds.w, bounds.h);
}

const Engine::Math::FloatRect& Engine::Drawable2D::GetBounds()
{
	return bounds;
}

std::shared_ptr<Engine::Texture2D> Engine::Drawable2D::GetTexture()
{
	return m_Texture;
}

bool Engine::Drawable2D::IsVisible()
{
	return m_Visible;
}

void Engine::Drawable2D::SetPosition(const Math::Vec2f& position)
{
	bounds.x = position.x;
	bounds.y = position.y;
}

void Engine::Drawable2D::Translate(float x, float y)
{
	bounds.x += x;
	bounds.y += y;
}

void Engine::Drawable2D::SetSize(const Math::Vec2f& size)
{
	bounds.w = size.x;
	bounds.h = size.y;
}

void Engine::Drawable2D::SetVisible(bool visible)
{
	m_Visible = visible;
}
