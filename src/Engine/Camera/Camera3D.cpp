#include "..\..\..\include\Engine\Camera\Camera3D.h"


#define PI 3.14159265358979323846264338327950288


namespace Engine
{


	Camera3D::Camera3D(float aspectRatio)
	{
		m_ProjectionMatrix = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 1000.f);

		m_roll = 0.0f;
		m_pitch = 0.0f;
		m_yaw = 0.0f;

		m_position = { 0.0f,0.0f,0.0f };
		m_LookDirection = {};

		m_ViewMatrix = {};

		
	}

	Camera3D::~Camera3D()
	{
	}

	void Camera3D::OnMove()
	{
		float dx = 0;
		float dy = 0;
		float dz = 0;

		glm::mat2 rotate {
			cos(m_yaw), -sin(m_yaw),
			sin(m_yaw),cos(m_yaw)
		}; 

		glm::vec2 f(0.0, 1.0);
		f = f * rotate;

		if (Input::IsKeyPressed(FATON_KEY_W)) 
		{
			dz -= f.y;
			dx -= f.x;
		}
		else if (Input::IsKeyPressed(FATON_KEY_S))
		{
			dz += f.y;
			dx += f.x;
		}
		else if (Input::IsKeyPressed(FATON_KEY_A))
		{
			dz += f.x;
			dx += -f.y;
		}
		else if (Input::IsKeyPressed(FATON_KEY_D)) 
		{
			dz -= f.x;
			dx -= -f.y;
		}
		else if (Input::IsKeyPressed(FATON_KEY_SPACE))
		{
			dy += 1;
		}
		else if (Input::IsKeyPressed(FATON_KEY_LSHIFT))
		{
			dy -= 1;
		}

		glm::mat4 mat = GetViewMatrix();
		glm::vec3 forward(mat[0][2], mat[1][2], mat[2][2]);
		glm::vec3 strafe(mat[0][0], mat[1][0], mat[2][0]);

	
		m_position.x += dx * m_CameraSpeed;
		m_position.z += dz * m_CameraSpeed;
		m_position.y += dy * m_CameraSpeed;

		UpdateView();
	}

	glm::vec3 Camera3D::GetPosition()
	{
		return m_position;
	}

	

	void Camera3D::SetPosition(glm::vec3 position)
	{
		m_position = position;
		UpdateView();
	}

	glm::mat4 Camera3D::GetViewMatrix() const 
	{
		return m_ViewMatrix;
	}

	glm::mat4 Camera3D::GetPorjectionMatrix() const
	{
		return m_ProjectionMatrix;
	}


	glm::mat4 Camera3D::GetViewProjectionMatrix() const
	{
		return m_ProjectionMatrix * m_ViewMatrix;
	}

	void Camera3D::UpdateView()
	{

		glm::mat4 matRoll = glm::mat4(1.0f); //identity matrix; 
		glm::mat4 matPitch = glm::mat4(1.0f);//identity matrix
		glm::mat4 matYaw = glm::mat4(1.0f);  //identity matrix

		// roll, pitch and yaw
		matRoll = glm::rotate(matRoll, m_roll, glm::vec3(0.0f, 0.0f, 1.0f));
		matPitch = glm::rotate(matPitch, m_pitch, glm::vec3(1.0f, 0.0f, 0.0f));
		matYaw = glm::rotate(matYaw, m_yaw, glm::vec3(0.0f, 1.0f, 0.0f));

		glm::mat4 rotate = matRoll * matPitch * matYaw;

		glm::mat4 translate = glm::mat4(1.0f);
		translate = glm::translate(translate, -m_position);

		m_ViewMatrix = rotate * translate;

		// Work out Look Vector
		glm::mat4 inverseView = glm::inverse(m_ViewMatrix);

		m_LookDirection.x = inverseView[2][0];
		m_LookDirection.y = inverseView[2][1];
		m_LookDirection.z = inverseView[2][2];
	}

	void Camera3D::UpdateProjection(float aspectRatio)
	{
		m_ProjectionMatrix = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 1000.0f);
	}


	void Camera3D::OnMouseHandle(Math::Vec2f  mousePos, float DeltaTime)
	{
		float mouseDX, mouseDY;

		float lastX = 720, lastY = 450;

	

		 mouseDX = lastX - mousePos.x;
		 mouseDY = lastY - mousePos.y;



		glm::vec2 mouseDelta{ mouseDX,mouseDY };

		MouseMoved(mouseDelta,DeltaTime);
	}
	
	void Camera3D::MouseMoved(glm::vec2 delta,float DeltaTime)
	{
		m_yaw += 0.001f * (delta.x) * DeltaTime;
		m_pitch += 0.001f * (delta.y) * DeltaTime;

		m_pitch = glm::clamp<float>(m_pitch, -PI / 2, PI/ 2);

		UpdateView();
	}

}
