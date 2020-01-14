#include "glDrawable.h"



glDrawable::glDrawable(unsigned int vao,GLsizei indices) : vao_id(vao), indicesCount(indices)
{
}

glDrawable::~glDrawable()
{
}
void glDrawable::Bind() const
{
	glBindVertexArray(this->vao_id);
}

void glDrawable::Draw() const
{
	glDrawElements(GL_TRIANGLES,this->indicesCount, GL_UNSIGNED_INT, nullptr);
	glBindTexture(GL_TEXTURE_2D, 0);
}

std::unique_ptr<Engine::Drawable> Engine::Drawable::Create(unsigned int vao, unsigned indices)
{
	return std::make_unique<glDrawable>(vao, indices);
}



