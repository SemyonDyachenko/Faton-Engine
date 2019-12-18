//
// Created by semyon on 16.12.2019.
//

#ifndef MY_OWN_GAME_OPENGLRENDERERAPI_H
#define MY_OWN_GAME_OPENGLRENDERERAPI_H


#include "../../include/Engine/renderer/RendererAPI.h"

class OpenGLRendererAPI : public Engine::RendererAPI {

public:
    virtual void Init() override;

    virtual void Clear(Engine::Math::Color3<float> & color) override;


    virtual void Draw() override;
};


#endif //MY_OWN_GAME_OPENGLRENDERERAPI_H
