//
// Created by semyon on 16.12.2019.
//

#ifndef MY_OWN_GAME_OPENGLVERTEXARRAY_H
#define MY_OWN_GAME_OPENGLVERTEXARRAY_H


#include <vector>
#include "../../include/Engine/renderer/VertexArray.h"
#include "../../include/Engine/renderer/VertexBuffer.h"
#include <GL/glew.h>

class OpenGLVertexArray : public Engine::VertexArray {
private:
    Engine::IndexBuffer *indexBuffer;
    GLuint id;
    unsigned int number_vertices;

    std::vector<std::unique_ptr<Engine::VertexBuffer>> vertexBuffers;

public:
    OpenGLVertexArray();
    virtual ~OpenGLVertexArray();


    void Bind() override;
    void Unbind() override;

    void AddIndexBuffer(Engine::IndexBuffer * buffer) override;

    void AddVertexBuffer(Engine::VertexBuffer& vertexBuffer) override;

    Engine::IndexBuffer& GetIndexBuffer() const override;


};


#endif //MY_OWN_GAME_OPENGLVERTEXARRAY_H
