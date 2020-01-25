#include "../../../include/Engine/renderer/Renderer3D.h"


namespace Engine
{
	
	std::unique_ptr<RendererAPI> RenderCommand::m_RendererAPI = RendererAPI::Create();
	
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

	void Renderer3D::Render(Drawable3D& drawable3d)
	{
		
	}
}
