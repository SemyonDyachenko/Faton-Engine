#include "..\..\..\include\Engine\Camera\Camera3D.h"


namespace Engine
{



	Camera3D::Camera3D(const glm::vec3& position, float fov, float aspectRatio, float znear, float zfar)
	{
		m_Perspective = glm::perspective(fov, aspectRatio, znear, zfar);
		m_Position = position;
		m_Forward = glm::vec3(0, 0, 1);
		m_Up = glm::vec3(0, 1, 0);
	}

	Camera3D::~Camera3D()
	{
	}

	glm::mat4 Camera3D::GetViewProjection() const
	{
		return m_Perspective * glm::lookAt(m_Position, m_Position + m_Forward, m_Up);
	}

}
