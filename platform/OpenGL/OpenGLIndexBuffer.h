//
// Created by semyon on 18.12.2019.
//

#ifndef MY_OWN_GAME_OPENGLINDEXBUFFER_H
#define MY_OWN_GAME_OPENGLINDEXBUFFER_H

#include <GL/glew.h>
#include "../../include/Engine/renderer/IndexBuffer.h"

class OpenGLIndexBuffer : public Engine::IndexBuffer {
private:
    unsigned int id;
    unsigned int count;
public:
    OpenGLIndexBuffer(unsigned int* data,unsigned int count);

    virtual ~OpenGLIndexBuffer();

    virtual void Bind() const override;
    virtual void Unbind() const override;

    unsigned int GetCount() const override;
};


#endif //MY_OWN_GAME_OPENGLINDEXBUFFER_H
