//
// Created by semyon on 08.12.2019.
//

#ifndef MY_OWN_GAME_DRAWABLE_H
#define MY_OWN_GAME_DRAWABLE_H

#include "Renderer2D.h"

namespace Engine {

    class Drawable {
    protected:
     //   friend class Renderer2D;

//        virtual void Draw(Renderer2D & renderer2D) const = 0;
    public:
        virtual ~Drawable();
    };

}

#endif //MY_OWN_GAME_DRAWABLE_H
