//
// Created by semyon on 01.12.2019.
//

#ifndef MY_OWN_GAME_CAMERA_H
#define MY_OWN_GAME_CAMERA_H

#include "../Math/Vector2.h"

namespace Engine {

    class Camera {
    private:
        float rotation;
        Math::Vector2<float> position;



    public:
        Camera(float left,float right,float top,float bottom);

        const Math::Vector2<float> GetPosition() const;

        void SetPosition(const Math::Vector2<float> position);



        const
    };

}

#endif //MY_OWN_GAME_CAMERA_H
