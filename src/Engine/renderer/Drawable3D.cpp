#include "../../../include/Engine/renderer/Drawable3D.h"


namespace  Engine
{

	Drawable3D::Drawable3D(const Math::Vec2f& position, const Math::Vec2f& size)
	{
	}

	Engine::Drawable3D::~Drawable3D()
	{
	}

	const Engine::Math::Vec3f& Engine::Drawable3D::GetPosition() const
	{
		return Math::Vec3f(0.0f, 0.0f, 0.0f);
	}

	const Engine::Math::Vec3f& Engine::Drawable3D::GetSize() const
	{
		return Math::Vec3f(0.0f, 0.0f, 0.0f);
	}

	void Engine::Drawable3D::OnRender(Camera3D& camera)
	{
	}
}