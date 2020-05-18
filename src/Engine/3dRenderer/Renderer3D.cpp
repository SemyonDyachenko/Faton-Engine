#include "../../../include/Engine/3dRenderer/Renderer3D.h"


namespace Engine
{
	

	void Renderer3D::Init()
	{
		RenderCommand::Init3D();
	}

	void Renderer3D::BeginScene(Entity::Scene3D& scene)
	{
		
	}

	void Renderer3D::EndScene()
	{
		
	}

	void Renderer3D::DrawCube(Camera3D& camera, Math::Vec3f& position, float width)
	{
	}

	void Renderer3D::DrawCube(Camera3D& camera, Math::Vec3f& position, float width, Math::Color3f& color)
	{
	}

	void Renderer3D::DrawCube(Camera3D& camera, Math::Vec3f& position, float width, float rotation, Math::Color3f& color)
	{
	}

	void Renderer3D::Render(Drawable3D& drawable3d)
	{
		
	}
}
