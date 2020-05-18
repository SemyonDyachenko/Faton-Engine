#ifndef ENGINE_RENDERER_3D_H
#define ENGINE_RENDERER_3D_H


#include "Drawable3D.h"



#include "../Entity/Scene3D.h"
#include "../renderer/RendererAPI.h"

namespace Engine
{
	

	class Renderer3D
	{
	public:

		static void Init();

		static void BeginScene(Entity::Scene3D & scene);

		static void EndScene();

		static void DrawCube(Camera3D& camera, Math::Vec3f& position, float width);
		static void DrawCube(Camera3D& camera, Math::Vec3f& position, float width,Math::Color3f & color);
		static void DrawCube(Camera3D& camera, Math::Vec3f& position, float width,float rotation,Math::Color3f & color);

		
		static void Render(Drawable3D& drawable3d);
		
	};
	
}



#endif