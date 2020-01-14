//
// Created by semyon on 08.12.2019.
//

#ifndef MY_OWN_GAME_DRAWABLE_H
#define MY_OWN_GAME_DRAWABLE_H

#include <memory>



namespace Engine {


    enum class DrawableTypes
    {
        SPRITE

    };


    class Drawable {
    public:

        virtual ~Drawable();

		virtual void Bind() const = 0;

		virtual void Draw() const = 0;
    	
        static std::unique_ptr<Drawable> Create(unsigned int vao,unsigned int indices);

    };
}

#endif //MY_OWN_GAME_DRAWABLE_H

