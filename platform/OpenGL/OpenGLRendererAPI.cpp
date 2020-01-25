//
// Created by semyon on 16.12.2019.
//

#include "OpenGLRendererAPI.h"

void OpenGLRendererAPI::Init() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);



	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		printf("Error\n");

}

void OpenGLRendererAPI::Init3D()
{
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);


	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		printf("Error\n");
}

void OpenGLRendererAPI::Clear(Engine::Math::Color3<float> &color) {
glClearColor(color.red,color.green,color.blue,color.m_Alpha);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLRendererAPI::Clear(Engine::Window& window)
{
}

void OpenGLRendererAPI::SetViewport(unsigned x, unsigned y, unsigned width, unsigned height)
{
	glViewport(x, y, width, height);
}


void OpenGLRendererAPI::Draw(Engine::VertexArray* vertexArray) {

}

