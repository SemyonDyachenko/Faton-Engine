//
// Created by semyon on 16.12.2019.
//

#include <GL/glew.h>
#include "OpenGLRendererAPI.h"

void OpenGLRendererAPI::Init() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);
}

void OpenGLRendererAPI::Clear(Engine::Math::Color3<float> &color) {
glClearColor(color.red,color.green,color.blue,color.m_Alpha);
glClear(GL_COLOR_BUFFER_BIT);
}


void OpenGLRendererAPI::Draw(Engine::VertexArray* vertexArray) {
//glDrawElements(GL_TRIANGLES,vertexArray->GetIndexBuffer()->count,GL_UNSIGNED_INT,nullptr);
glBindTexture(GL_TEXTURE_2D,0);
}

void OpenGLRendererAPI::Clear(Engine::Window &window) {
    window.Clear(Engine::Math::Color3<float>(0,0,0,1));
}

