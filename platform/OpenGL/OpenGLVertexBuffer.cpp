//
// Created by semyon on 18.12.2019.
//

#include "OpenGLVertexBuffer.h"

OpenGLVertexBuffer::OpenGLVertexBuffer(float *data, unsigned int size) {
glGenBuffers(1,&id);
glBindBuffer(GL_ARRAY_BUFFER,id);
glBufferData(GL_ARRAY_BUFFER,size,data,GL_STATIC_DRAW);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer() {
glDeleteBuffers(1,&id);
}

void OpenGLVertexBuffer::Bind() const {
glBindBuffer(GL_ARRAY_BUFFER,id);
}

void OpenGLVertexBuffer::Unbind() const {
glBindBuffer(GL_ARRAY_BUFFER,0);
}
