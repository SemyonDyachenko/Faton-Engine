#ifndef ENGINE_CAMERA_3D_H
#define ENGINE_CAMERA_3D_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include "../Math/Math.h"

#include "../Core/Input.h"
#include "../Core/EngineKeys.h"

#include "../Core/Window.h"

#include <memory>

namespace Engine
{



	class Camera3D
	{
	public:
		Camera3D(float aspectRatio);
		
		virtual ~Camera3D();

		void OnUpdate(float DeltaTime);

		void MouseHandle(float x, float y, std::unique_ptr<Window>& window, bool constrainPitch = true);

		const glm::mat4 & GetViewProjectionMatrix();

		const glm::mat4& GetViewMatrix();
		const glm::mat4& GetProjectionMatrix();

	

	private:
		glm::vec3 m_cameraPosition;
		glm::vec3 m_cameraDirection;
		glm::vec3 m_cameraTarget;
		glm::vec3 m_up;
		glm::vec3 m_cameraUp;
		glm::vec3 m_cameraRight;
		glm::vec3 m_cameraFront;

		float m_yaw;
		float m_pitch;
		float m_roll;
		float m_fov;
		float m_aspectRatio;

		glm::mat4 m_viewMatrix;
		glm::mat4 m_projectionMatrix;
	
	};

	
}




#endif