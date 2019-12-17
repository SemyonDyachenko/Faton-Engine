//
// Created by semyon on 17.12.2019.
//

#ifndef MY_OWN_GAME_INDEXBUFFER_H
#define MY_OWN_GAME_INDEXBUFFER_H

#include <memory>

namespace Engine {


    class IndexBuffer {
    public:
        virtual ~IndexBuffer() = default;

        virtual void Bind() = 0;
        virtual void Unbind() = 0;

        virtual unsigned int GetCount() const = 0;

        static std::shared_ptr<IndexBuffer> Create();

    };

}

#endif //MY_OWN_GAME_INDEXBUFFER_H
