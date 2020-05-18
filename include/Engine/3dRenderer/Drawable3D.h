#ifndef ENGINE_DRAWABLE_3D_H
#define ENGINE_DRAWABLE_3D_H

 
#include "../Math/Math.h"
#include "../renderer/Renderer2D.h"
#include "../Camera/Camera3D.h"


namespace Engine
{

	class Drawable3D
	{
	protected:
		Math::Vec3f m_Position;

	public:
		virtual void OnRender(Camera3D & camera) = 0;

		virtual void SetPosition(float x, float y,float z);
		virtual Math::Vec3f GetPosition() const;



		virtual ~Drawable3D() = default;
		
	};
	
}



#endif