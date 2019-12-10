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
    protected:
     // friend class Renderer2D;

     // static void Draw(Window & window);
    public:

        virtual ~Drawable();


        static std::unique_ptr<Drawable> Create(DrawableTypes type);

    };
}

#endif //MY_OWN_GAME_DRAWABLE_H

// 10 ДЕКАБРЯ
// СОЗДАНИЕ СТРУКТУРЫ ПОКАЗА ОБЬЕКТА с ПОМОШЬю renderer2d или WIndow
// Вывод спрайтов на экран
