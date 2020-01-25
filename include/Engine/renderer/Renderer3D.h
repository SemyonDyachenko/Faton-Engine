#ifndef ENGINE_RENDERER_3D_H
#define ENGINE_RENDERER_3D_H


#include "Drawable3D.h"


#include "Renderer2D.h"

#include "../Entity/Scene3D.h"
#include "RendererAPI.h"

namespace Engine
{
	

	class Renderer3D
	{
	private:
		static std::unique_ptr<RendererAPI> m_RendererAPI;
	public:

		static void Init();

		static void BeginScene(Entity::Scene3D & scene);

		static void EndScene();
		
		static void Render(Drawable3D& drawable3d);
		
	};
	
}



#endif