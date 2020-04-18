//
// Created by semyon on 01.12.2019.
//

#ifndef MY_OWN_GAME_CAMERA_H
#define MY_OWN_GAME_CAMERA_H

#include "../Math/Vector3.hpp"

#include <memory>
#include "../Core/Timer.h"

#include <glm/gtc/matrix_transform.hpp>
#include "../../../include/Engine/Core/Input.h"
#include "../../../include/Engine/Core/EngineKeys.h"
#include <glm/glm.hpp>
#include "../Math/Vector2.hpp"

namespace Engine {

    class Camera2D {
    private:
        float Rotation = 0.0f;
        float ZoomFactor = 0.0f;

		float AspectRatio;
    	
		Math::Vec2f Size;
		Math::Vec3f Position = {0.0, 0.0, 0.0};
    	
		bool onControl;
		float CameraSpeed;
		float ZoomSpeed;

		glm::mat4 ViewMatrix;
		glm::mat4 ProjectionMatrix;
		glm::mat4 ViewProjectionMatrix;
		
    public:
		Camera2D(float aspectRatio);
		virtual ~Camera2D();


		void Update(float DeltaTime);
    	
        const Math::Vec3f GetPosition() const;

		const glm::mat4& GetProjectionMatrix() const;
		const glm::mat4& GetViewMatrix() const;
		const glm::mat4& GetViewProjectionMatrix() const;
    	

		void MoveLeft(float speed,float DeltaTime);
		void MoveRight(float speed, float DeltaTime);
		void MoveDown(float speed, float DeltaTime);
		void MoveUp(float speed, float DeltaTime);

		const bool& IsControl();

		const float& GetZoomFactor() const;

		const Math::Vec2f GetSize() const;

		float GetRotation() const;

		//Controller

		void Zoom(float zoomSpeed,float DeltaTime);

		void OnControl(bool control);

		void SetCameraSpeed(float cameraSpeed);

		void SetZoomSpeed(float zoomSpeed);

		void SetPojection(float left, float right, float bottom, float top);
    	
        void SetPosition(const Math::Vec3f position);

		void SetSize(float width, float height);

		void SetSize(const Math::Vec2f size);
    	
        void SetZoomFactor(float zoomFactor);

		void SetRotation(float RotationAngle);

		void ResetView();
		

      
    };

}

#endif //MY_OWN_GAME_CAMERA_H
