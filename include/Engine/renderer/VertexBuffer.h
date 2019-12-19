//
// Created by semyon on 17.12.2019.
//

#ifndef MY_OWN_GAME_VERTEXBUFFER_H
#define MY_OWN_GAME_VERTEXBUFFER_H

#include <memory>

namespace  Engine {

    class VertexBuffer {
    public:
        virtual ~VertexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        static std::shared_ptr<VertexBuffer> Create(float * data,unsigned int size);
    };


}
#endif //MY_OWN_GAME_VERTEXBUFFER_H
