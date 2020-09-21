#include "../../../include/Engine/3dRenderer/Entity3d.h"

namespace Engine
{


	Entity3d::Entity3d(TexturedModel * model, Math::Vec3f position, float rotatedX, float rotatedY, float rotatedZ, float scaleFactor)
		: 
		m_Model(model),
		m_Position(position),
		m_RotatedX(rotatedX),
		m_RotatedY(rotatedY),
		m_RotatedZ(rotatedZ),
		m_ScaleFactor(scaleFactor)
	{
		
		m_ViewShader = Shader::Create("Shaders/3D/vertexShader.glsl","Shaders/3D/fragmentShader.glsl");

		m_Transform = glm::translate(glm::mat4(1.0f), { m_Position.x,m_Position.y,m_Position.z }) * scale(glm::mat4(m_ScaleFactor), { 1.0f,1.0f,1.0f });
	}


	void Entity3d::Translate(float deltaX, float deltaY, float deltaZ)
	{
		m_Position.x += deltaX;
		m_Position.y += deltaY;
		m_Position.z += deltaZ;
	}

	void Entity3d::Rotate(float deltaX, float deltaY, float deltaZ)
	{
		m_RotatedX += deltaX;
		m_RotatedY += deltaY;
		m_RotatedZ += deltaZ;
	}


	TexturedModel& Entity3d::GetModel() const
	{
		return *m_Model;
	}

	void Entity3d::SetPosition(float x, float y, float z)
	{
		m_Position = { x,y,z };
	}

	Math::Vec3f Entity3d::GetPosition() const
	{
		return m_Position;
	}

	void Entity3d::SetScaleFactor(float scaleFactor)
	{
		m_ScaleFactor = scaleFactor;
	}

	float Entity3d::GetScaleFactor() const
	{
		return m_ScaleFactor;
	}

	void Entity3d::OnRender(Camera3D& camera)
	{

		m_ViewShader->Bind();

		m_ViewShader->SetMat4("viewMatrix", camera.GetViewMatrix());
		m_ViewShader->SetMat4("projectionMatrix", camera.GetProjectionMatrix());

		m_ViewShader->SetFloat4("m_Color", { 1,0.3,0.6,1 });

		//m_ViewShader->SetMat4("Transform", m_Transform);
		

		m_Model->GetTexture()->Bind();
		m_Model->GetMesh().OnRender();

		m_ViewShader->Unbind();
	}

	void Entity3d::TransformRecalculate()
	{
		m_Transform = glm::translate(glm::mat4(1.0f), { m_Position.x,m_Position.y,m_Position.z }) * scale(glm::mat4(m_ScaleFactor), { 1.0f,1.0f,1.0f }) * glm::rotate(glm::mat4(1.0f), 1.0f, { m_RotatedX,m_RotatedY,m_RotatedZ });
	}

}