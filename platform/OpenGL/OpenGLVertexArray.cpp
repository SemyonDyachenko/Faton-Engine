//
// Created by semyon on 16.12.2019.
//

#include "OpenGLVertexArray.h"

OpenGLVertexArray::OpenGLVertexArray() {

}

void OpenGLVertexArray::Bind() {

}

void OpenGLVertexArray::Unbind() {

}

void OpenGLVertexArray::AddIndexBuffer(Engine::IndexBuffer *buffer) {

}

Engine::IndexBuffer &OpenGLVertexArray::GetIndexBuffer() const {
    return *this->indexBuffer;
}

