#ifndef ENGINE_CAMERA_3D_H
#define ENGINE_CAMERA_3D_H

#include <glm/glm.hpp>

#include "../Math/Math.h"

#include "../Entity/Entity.h"

namespace Engine
{

	class Camera3D
	{
	public:
		Camera3D(const glm::vec3 & position,float fov,float aspectRatio,float znear,float zfar);


		virtual ~Camera3D();

		glm::mat4 GetViewProjection() const;

	private:
		glm::mat4 m_Perspective;
		glm::vec3 m_Position;
		glm::vec3 m_Forward;
		glm::vec3 m_Up;


	};
	
}




#endif