//
// Created by semyon on 16.12.2019.
//

#include "OpenGLVertexArray.h"
#include <iostream>


OpenGLVertexArray::OpenGLVertexArray()
{
	glCreateVertexArrays(1, &vao_id);
}

OpenGLVertexArray::~OpenGLVertexArray()
{
	glDeleteVertexArrays(1,&vao_id);
	glDeleteBuffers(bufferObjects.size(), bufferObjects.data());
	bufferObjects.clear();
	vao_id = 0;
	indicesCount = 0;
}

void OpenGLVertexArray::CreateVAO()
{
	glGenVertexArrays(1, &vao_id);
}

void OpenGLVertexArray::Bind() const
{
	glBindVertexArray(vao_id);
}

void OpenGLVertexArray::Unbind() const
{
	glBindVertexArray(0);
}

void OpenGLVertexArray::AddVertexBuffer(const std::vector<float> & vertices)
{
	Bind();

	
	GLuint vbo; // vertex buffer
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);



	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//glEnableVertexAttribArray(0);


	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, (vertices.size() / 4) * sizeof(float), (const GLvoid*)12);
	//glEnableVertexAttribArray(1);

	bufferObjects.push_back(vbo);
}


void OpenGLVertexArray::AddIndexBuffer(const std::vector<unsigned int> & indices)
{
	Bind();

	GLuint ebo; // element buffer

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);


	bufferObjects.push_back(ebo);
	indicesCount = indices.size();
	
}


std::unique_ptr<Engine::Drawable> OpenGLVertexArray::GetDrawable() const 
{
	return Engine::Drawable::Create(vao_id, indicesCount);
}
