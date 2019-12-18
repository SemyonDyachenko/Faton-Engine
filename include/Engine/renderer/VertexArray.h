//
// Created by semyon on 17.12.2019.
//

#ifndef MY_OWN_GAME_VERTEXARRAY_H
#define MY_OWN_GAME_VERTEXARRAY_H


#include <memory>

#include "IndexBuffer.h"
#include "VertexBuffer.h"

namespace Engine {

    class VertexArray {
    public:
        virtual ~VertexArray()= default;


        virtual void Bind() = 0;
        virtual void Unbind() = 0;

        virtual void AddIndexBuffer(IndexBuffer * buffer) = 0;

        virtual IndexBuffer& GetIndexBuffer() const = 0;

        virtual void AddVertexBuffer(VertexBuffer & vertexBuffer) = 0;

        static std::shared_ptr<VertexArray> Create();
    };

}

#endif //MY_OWN_GAME_VERTEXARRAY_H
