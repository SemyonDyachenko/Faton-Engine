//
// Created by semyon on 16.12.2019.
//

#ifndef MY_OWN_GAME_OPENGLRENDERERAPI_H
#define MY_OWN_GAME_OPENGLRENDERERAPI_H


#include "../../include/Engine/renderer/RendererAPI.h"
#include <GL/glew.h>

class OpenGLRendererAPI : public Engine::RendererAPI {

public:
    virtual void Init() override;

    virtual void Clear(Engine::Math::Color3<float> & color) override;

    virtual void Clear(Engine::Window & window) override;

    virtual void Draw(Engine::VertexArray * vertexArray) override;
};


#endif //MY_OWN_GAME_OPENGLRENDERERAPI_H
