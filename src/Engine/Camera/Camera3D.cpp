#include "..\..\..\include\Engine\Camera\Camera3D.h"


#define PI 3.14159265358979323846264338327950288


namespace Engine
{



	Camera3D::Camera3D(float aspectRatio)
	{
		m_cameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
		m_cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
		m_cameraDirection = glm::normalize(m_cameraPosition - m_cameraTarget);
		m_cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		m_up = glm::vec3(0.0f, 1.0f, 0.0f);
		m_cameraRight = glm::normalize(glm::cross(m_up, m_cameraDirection));
		m_cameraUp = glm::cross(m_cameraDirection, m_cameraRight);
		
		m_yaw = -90.f;
		m_roll = 0.0f;
		m_pitch = 0.0f;
		m_aspectRatio = aspectRatio;
		m_fov = 45.0f;

		m_projectionMatrix = glm::perspective(glm::radians(m_fov), aspectRatio, 0.1f, 100.f);
		m_viewMatrix =glm::lookAt(m_cameraDirection,m_cameraPosition+m_cameraFront, m_cameraUp);

	}

	Camera3D::~Camera3D()
	{
	}

	void Camera3D::OnUpdate(float DeltaTime)
	{
		m_cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		m_cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);



		if (Input::IsKeyPressed(FATON_KEY_W)) {
			m_cameraPosition += 0.005f * DeltaTime * m_cameraFront;
			
		}
		else if (Input::IsKeyPressed(FATON_KEY_S)) {
			m_cameraPosition -= 0.005f * DeltaTime * m_cameraFront;
		}
		else if (Input::IsKeyPressed(FATON_KEY_A)) {
			m_cameraPosition -= glm::normalize(glm::cross(m_cameraFront, m_cameraUp)) * 0.005f * DeltaTime;
		}
		else if (Input::IsKeyPressed(FATON_KEY_D)) {
			m_cameraPosition += glm::normalize(glm::cross(m_cameraFront, m_cameraUp)) * 0.005f * DeltaTime;
		}


		

		m_viewMatrix = glm::lookAt(m_cameraPosition, m_cameraPosition + m_cameraFront, m_cameraUp);
	}

	void Camera3D::MouseHandle(float x, float y, std::unique_ptr<Window>& window, bool constrainPitch)
	{
		float lastX = window->GetWidth() / 2;
		float lastY = window->GetHeight() / 2;

		float xoffset = x - lastX;
		float yoffset = lastY - y;

		float sensitivity = 0.01f;
		xoffset *= sensitivity;
		yoffset *= sensitivity;
		lastX = x;
		lastY = y;


		m_yaw += xoffset;
		m_pitch += yoffset;

		// Make sure that when pitch is out of bounds, screen doesn't get flipped
		if (m_pitch > 89.0f)
		{
			m_pitch = 89.0f;
		}
		if (m_pitch < -89.0f)
		{
			m_pitch = -89.0f;
		}

		glm::vec3 front;
		front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
		front.y = sin(glm::radians(m_pitch));
		front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
		m_cameraFront = glm::normalize(front);
		// Also re-calculate the Right and Up vector
		m_cameraRight = glm::normalize(glm::cross(m_cameraFront, m_up));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		m_cameraUp = glm::normalize(glm::cross(m_cameraRight, m_cameraFront));

		m_viewMatrix = glm::lookAt(m_cameraPosition, m_cameraPosition + m_cameraFront, m_cameraUp);
	}

	

	const glm::mat4& Camera3D::GetViewProjectionMatrix()
	{
		return m_viewMatrix * m_projectionMatrix;
	}

	const glm::mat4& Camera3D::GetViewMatrix()
	{
		return m_viewMatrix;
	}

	const glm::mat4& Camera3D::GetProjectionMatrix()
	{
		return m_projectionMatrix;
	}

}
