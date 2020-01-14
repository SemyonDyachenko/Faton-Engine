//
// Created by semyon on 01.12.2019.
//

#include "../../../include/Engine/Camera/Camera.h"
#include <SFML/Window/Keyboard.hpp>
#include <algorithm>


namespace Engine{


    Camera::Camera(float aspectRatio) : AspectRatio(aspectRatio)
	{
		ProjectionMatrix = glm::ortho(-AspectRatio*ZoomFactor,AspectRatio*ZoomFactor, -ZoomFactor, ZoomFactor, -1.0f, 1.0f);

		ViewMatrix = glm::mat4(1.0f);
    	
		ViewProjectionMatrix = ProjectionMatrix * ViewMatrix;

		CameraSpeed = 0.1f;
    }

    Camera::~Camera()
    {
    }

    void Camera::Update(float time)
    {

    	//movement camera
    	if(Input::IsKeyPressed(FATON_KEY_A))
    	{
			Position.x -= cos(glm::radians(Rotation)) * CameraSpeed;
			Position.y -= sin(glm::radians(Rotation)) *CameraSpeed;
			
    	}
		else if (Input::IsKeyPressed(FATON_KEY_D))
		{
			Position.x += cos(glm::radians(Rotation)) * CameraSpeed;
			Position.y += sin(glm::radians(Rotation)) * CameraSpeed;
		}
		else if(Input::IsKeyPressed(FATON_KEY_W))
    	{
			Position.x += -sin(glm::radians(Rotation)) *CameraSpeed;
			Position.y += cos(glm::radians(Rotation)) * CameraSpeed;
		
    	}
		else if(Input::IsKeyPressed(FATON_KEY_S))
		{
			Position.x -= -sin(glm::radians(Rotation)) * CameraSpeed;
			Position.y -= cos(glm::radians(Rotation)) *CameraSpeed;
			
		}

		if(Input::IsKeyPressed(FATON_KEY_UP))
		{
			ZoomFactor -= 0.1f;
		}

		else if(Input::IsKeyPressed(FATON_KEY_DOWN))
		{
			ZoomFactor += 0.1f;
		}

		this->SetZoomFactor(ZoomFactor);
    	
		this->ZoomFactor = std::max(ZoomFactor, 0.25f);

		this->SetPojection(-AspectRatio * ZoomFactor, AspectRatio*ZoomFactor, -ZoomFactor, ZoomFactor);

		

    	
		this->SetPosition(Position);
		
    }


    const Math::Vec3f Camera::GetPosition() const {
        return this->Position;
    }

    const glm::mat4& Camera::GetProjectionMatrix() const
    {
		return ProjectionMatrix;
    }

    const glm::mat4& Camera::GetViewMatrix() const
    {
		return ViewMatrix;
    }

    const glm::mat4& Camera::GetViewProjectionMatrix() const
    {
		return ViewProjectionMatrix;
    }

  
    const float& Camera::GetZoomFactor() const
    {
		return this->ZoomFactor;
    }

    const Math::Vec2f Camera::GetSize() const
    {
		return this->Size;
    }

    float Camera::GetRotation() const
    {
		return this->Rotation;
    }

    void Camera::SetPojection(float left, float right, float bottom, float top)
    {
		this->ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
		ViewProjectionMatrix = ProjectionMatrix * ViewMatrix;
    }

    //Controller

    void Camera::SetPosition(const Math::Vec3f position)
    {
		this->Position = position;
		ResetView();
    }

    void Camera::SetSize(float width, float height)
    {
		this->Size.x = width;
		this->Size.y = height;
    }

    void Camera::SetSize(const Math::Vec2f size)
    {
		this->SetSize(size.x, size.y);
    }

    void Camera::SetZoomFactor(float zoomFactor) {
        this->ZoomFactor = zoomFactor;
		ResetView();
    }

    void Camera::SetRotation(float RotationAngle)
    {
		this->Rotation = RotationAngle;
		ResetView();
    }

    void Camera::ResetView()
    {
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(Position.x, Position.y, Position.z)) * 
			glm::rotate(glm::mat4(1.0f), glm::radians(Rotation), glm::vec3(0, 0, 1));

		ViewMatrix = glm::inverse(transform);

		ViewProjectionMatrix = ProjectionMatrix * ViewMatrix;
    }
}
