//
// Created by semyon on 11.12.2019.
//

#ifndef MY_OWN_GAME_COLLISION_H
#define MY_OWN_GAME_COLLISION_H
#include "../Math/Math.h"

namespace Engine {

    namespace Physics {


        class Collision {
        public:
			static bool Intersects(const Math::FloatRect& rectA, const Math::FloatRect & rectB);
        };

    }
}


#endif //MY_OWN_GAME_COLLISION_H
