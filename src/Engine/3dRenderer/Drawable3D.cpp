#include "../../../include/Engine/3dRenderer/Drawable3D.h"


namespace  Engine
{
	void Drawable3D::SetPosition(float x, float y,float z)
	{
		m_Position = { x,y,z };
	}


	Math::Vec3f Drawable3D::GetPosition() const
	{
		return m_Position;
	}
}