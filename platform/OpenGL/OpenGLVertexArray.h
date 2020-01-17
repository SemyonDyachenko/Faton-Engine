//
// Created by semyon on 16.12.2019.
//

#ifndef MY_OWN_GAME_OPENGL_VERTEXARRAY_H
#define MY_OWN_GAME_OPENGL_VERTEXARRAY_H


#include <vector>
#include "../../include/Engine/renderer/VertexArray.h"

#include <GL/glew.h>

class OpenGLVertexArray : public Engine::VertexArray {
public:
	OpenGLVertexArray();
	virtual ~OpenGLVertexArray();

	virtual void CreateVAO() override;	
    virtual void Bind() const override;
    virtual void Unbind() const override;

    virtual void AddIndexBuffer(const std::vector<unsigned int> & indices) override;

	std::unique_ptr < Engine::Drawable> GetDrawable() const  override;

    virtual void AddVertexBuffer(const std::vector<float> & vertices) override;

private:
	uint32_t vao_id;
	GLsizei  indicesCount = 0;
	std::vector<GLuint> bufferObjects;


};


#endif //MY_OWN_GAME_OPENGL_VERTEXARRAY_H
