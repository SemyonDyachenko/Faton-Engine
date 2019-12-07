//
// Created by semyon on 01.12.2019.
//

#ifndef MY_OWN_GAME_CAMERA_H
#define MY_OWN_GAME_CAMERA_H

#include "../Math/Vector2.hpp"
#include <memory>

namespace Engine {

    class Camera {
    private:
        float rotation = 0.0f;
        float zoomFactor;
        Math::Vector2<float> position= {0.0f,0.0f};




    public:
        Camera(float x,float y);

        Camera(Engine::Math::Vector2<float> position);

        virtual const Math::Vector2<float> GetPosition() const;

        virtual void SetPosition(const Math::Vector2<float> position);

        virtual void SetZoom(float zoomFactor);

        virtual ~Camera();
    };

}

#endif //MY_OWN_GAME_CAMERA_H
