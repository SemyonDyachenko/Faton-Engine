#ifndef ENGINE_DRAWABLE_3D_H
#define ENGINE_DRAWABLE_3D_H


#include "../Math/Math.h"

#include "../Camera/Camera3D.h"


namespace Engine
{

	class Drawable3D
	{

	public:
		virtual void OnRender(Camera3D & camera) = 0;

		virtual ~Drawable3D() = default;
		
	};
	
}



#endif