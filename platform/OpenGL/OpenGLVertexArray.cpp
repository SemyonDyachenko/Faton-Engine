//
// Created by semyon on 16.12.2019.
//

#include "OpenGLVertexArray.h"

OpenGLVertexArray::OpenGLVertexArray() {

}

void OpenGLVertexArray::Bind() {
glBindVertexArray(id);
}

void OpenGLVertexArray::Unbind() {
 glBindVertexArray(0);
}

void OpenGLVertexArray::AddIndexBuffer(Engine::IndexBuffer *buffer) {

}

Engine::IndexBuffer &OpenGLVertexArray::GetIndexBuffer() const {
    return *this->indexBuffer;
}

