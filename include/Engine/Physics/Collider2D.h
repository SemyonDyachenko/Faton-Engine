//
// Created by semyon on 07.12.2019.
//

#ifndef MY_OWN_GAME_COLLIDER2D_H
#define MY_OWN_GAME_COLLIDER2D_H

#include "../Math/Vector2.hpp"

namespace Engine {

    namespace Physics {

        class Collider2D {
        private:
            Engine::Math::Vector2<float> position;
        public:

            ~Collider2D() = default;

            virtual void GetPosition() = 0;

            virtual void Show() = 0;
        };

    }
}

#endif //MY_OWN_GAME_COLLIDER2D_H
