#include "../../../include/Engine/renderer/Drawable2D.h"
#include "../../../include/Engine/renderer/Renderer2D.h"


namespace Engine
{

	Drawable2D::Drawable2D(const Math::Vec2f& position, const Math::Vec2f& size) : m_Visible(true), m_Texture(nullptr), bounds(position.x, position.y, size.x, size.y)
	{


	}

	Drawable2D::~Drawable2D()
	{
	}



	const Math::Vec2f& Drawable2D::GetPosition() const
	{
		return Math::Vec2f(bounds.x, bounds.y);
	}

	const Math::Vec2f& Drawable2D::GetSize() const
	{
		return Math::Vec2f(bounds.w, bounds.h);
	}

	Math::FloatRect& Drawable2D::GetBounds()
	{
		return bounds;
	}

	std::shared_ptr<Texture2D> Drawable2D::GetTexture()
	{
		return m_Texture;
	}

	bool Drawable2D::IsVisible()
	{
		return m_Visible;
	}

	void Drawable2D::SetPosition(const Math::Vec2f& position)
	{
		bounds.x = position.x;
		bounds.y = position.y;
	}

	void Drawable2D::Translate(float x, float y)
	{
		bounds.x += x;
		bounds.y += y;
	}

	void Drawable2D::SetSize(const Math::Vec2f& size)
	{
		bounds.w = size.x;
		bounds.h = size.y;
	}

	void Drawable2D::SetVisible(bool visible)
	{
		m_Visible = visible;
	}

}