#ifndef ENGINE_DRAWABLE_3D_H
#define ENGINE_DRAWABLE_3D_H


#include "../Math/Math.h"

#include "../Camera/Camera3D.h"


namespace Engine
{

	class Drawable3D
	{

	private:
		
	public:
		Drawable3D(const Math::Vec2f & position, const Math::Vec2f & size);

		virtual ~Drawable3D();

		const Math::Vec3f& GetPosition() const;

		const Math::Vec3f& GetSize() const;

		virtual void OnRender(Camera3D & camera);
		
	};
	
}



#endif