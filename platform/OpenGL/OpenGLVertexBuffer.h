//
// Created by semyon on 18.12.2019.
//

#ifndef MY_OWN_GAME_OPENGLVERTEXBUFFER_H
#define MY_OWN_GAME_OPENGLVERTEXBUFFER_H

#include <GL/glew.h>

#include "../../include/Engine/renderer/VertexBuffer.h"

class OpenGLVertexBuffer : public Engine::VertexBuffer {
private:
    unsigned int id;
public:
    OpenGLVertexBuffer(float *data,unsigned int size);

    virtual ~OpenGLVertexBuffer();

    virtual void Bind() const override;

    virtual void Unbind() const override;

};


#endif //MY_OWN_GAME_OPENGLVERTEXBUFFER_H
