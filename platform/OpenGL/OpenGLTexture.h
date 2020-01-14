#ifndef ENGINE_OPENGL_TEXTURE
#define ENGINE_OPENGL_TEXTURE


#include "../../include/Engine/renderer/Texture.h"
#include "../../lib/stb/stb_image.h"
#include "../../include/Engine/Core/Core.h"
#include <GL/glew.h>


class OpenGLTexture : public Engine::Texture2D
{
public:
	OpenGLTexture(std::string path);

	Engine::Math::Vec2f GetSize() const override;

	void Bind(unsigned int slot = 0) const override;
	
	virtual ~OpenGLTexture();
private:
	int m_width,  m_height;
	GLuint ID;
	GLenum target;
};



#endif 