//
// Created by semyon on 11.12.2019.
//

#ifndef MY_OWN_GAME_COLLISION_H
#define MY_OWN_GAME_COLLISION_H
#include "../Math/Math.h"
#include "BoxCollider2D.h"

namespace Engine {

    namespace Physics {

	    class Collision {
        public:
			static bool Intersects(BoxCollider2D& colliderA, BoxCollider2D & colliderB);
        };

    }
}


#endif //MY_OWN_GAME_COLLISION_H
