//
// Created by semyon on 18.12.2019.
//

#include "OpenGLIndexBuffer.h"

OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int *data, unsigned int count) {
glCreateBuffers(1,&id);
glBindBuffer(GL_ARRAY_BUFFER,id);
glBufferData(GL_ARRAY_BUFFER,count* sizeof(unsigned int),data,GL_STATIC_DRAW);
}

OpenGLIndexBuffer::~OpenGLIndexBuffer() {
glDeleteBuffers(1,&id);
}

void OpenGLIndexBuffer::Bind() const {
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,id);
}

void OpenGLIndexBuffer::Unbind() const {
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}

unsigned int OpenGLIndexBuffer::GetCount() const {
    return this->count;
}
