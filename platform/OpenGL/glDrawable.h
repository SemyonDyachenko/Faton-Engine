#ifndef GL_DRAWABLE_H
#define GL_DRAWABLE_H


#include "../../include/Engine/renderer/Drawable.h"
#include "../../include/Engine/renderer/VertexArray.h"
#include <GL/glew.h>




class glDrawable : public Engine::Drawable
{
private:
	const unsigned int  vao_id = 0;
	const unsigned int indicesCount = 0;
public:
	glDrawable(GLuint vao,GLsizei indices);
	virtual ~glDrawable();

	void Bind() const override;
	void Draw() const override;


};



#endif // GL_DRAWABLE_H