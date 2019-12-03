//
// Created by semyon on 01.12.2019.
//

#include "../../../include/Engine/Camera/Camera.h"


namespace Engine{


    Camera::Camera(float x, float y) {
        this->position.x = x;
        this->position.y = y;
    }

    const Math::Vector2<float> Camera::GetPosition() const {
        return this->position;
    }

    void Camera::SetPosition(const Math::Vector2<float> position)
    {
        this->position.x = position.x;
        this->position.y = position.y;
    }

    void Camera::SetZoom(float zoomFactor) {
        this->zoomFactor = zoomFactor;
    }

    Camera::~Camera() {

    }
}