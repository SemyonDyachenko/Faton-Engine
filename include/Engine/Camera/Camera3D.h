#ifndef ENGINE_CAMERA_3D_H
#define ENGINE_CAMERA_3D_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include "../Math/Math.h"

#include "../Core/Input.h"
#include "../Core/EngineKeys.h"

namespace Engine
{



	class Camera3D
	{
	public:
		Camera3D(float aspectRatio);
		
		virtual ~Camera3D();

		void OnMove();

		void OnMouseHandle(Math::Vec2f  mousePos, float DeltaTime);

		void MouseMoved(glm::vec2 delta, float DeltaTime);

		glm::vec3 GetPosition();


		void SetPosition(glm::vec3 position);


		glm::mat4 GetViewProjectionMatrix() const;

		glm::mat4 GetViewMatrix() const;
		glm::mat4 GetPorjectionMatrix() const;

		void UpdateProjection(float aspectRatio);
		void UpdateView();

	private:
		glm::mat4	m_ViewMatrix;
		glm::mat4	m_ProjectionMatrix;
		glm::vec3	m_position = {};
		float		m_pitch;
		float		m_yaw;
		float		m_roll;

		glm::vec3 m_LookDirection = {};

		float m_CameraSpeed = 0.05f;

		Math::Vec2f m_MousePos;
	};

	
}




#endif