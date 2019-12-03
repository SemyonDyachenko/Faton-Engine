//
// Created by semyon on 01.12.2019.
//

#include "../../../include/Engine/Camera/Camera.h"


namespace Engine{


    Camera::Camera(float left, float right, float top, float bottom) {

    }

    const Math::Vector2<float> Camera::GetPosition() const {
        return Math::Vector2<float>();
    }

    void Camera::SetPosition(const Math::Vector2<float> position)
    {
        this->position.x = position.x;
        this->position.y = position.y;
    }
}