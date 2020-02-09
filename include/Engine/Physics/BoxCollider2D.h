//
// Created by semyon on 05.12.2019.
//

#ifndef MY_OWN_GAME_BOXCOLLIDER2D_H
#define MY_OWN_GAME_BOXCOLLIDER2D_H

#include "Collider2D.h"
#include "../Math/Rect.hpp"

namespace Engine {

    namespace Physics {

        class BoxCollider2D : public Collider2D {
        public:
			BoxCollider2D(Math::FloatRect & bounds);

			virtual ~BoxCollider2D();

			Math::FloatRect &  GetBounds() const override;

        	void Show() override;
        private:
			Math::FloatRect& m_ColliderBounds;
        };
    }

}


#endif //MY_OWN_GAME_BOXCOLLIDER2D_H
