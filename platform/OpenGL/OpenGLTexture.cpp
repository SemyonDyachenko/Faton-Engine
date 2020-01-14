#include "OpenGLTexture.h"
#include <cassert>


OpenGLTexture::OpenGLTexture(std::string path)
{
	this->target = GL_TEXTURE_2D;
	
	int width, height, channels;
	
	stbi_set_flip_vertically_on_load(true);

	unsigned char * image = stbi_load(path.c_str(), &width, &height, &channels, 4);


	if (image == NULL)
	{
		FATON_ERROR_02(path.c_str());
	}

	m_width = width;
	m_height = height;

	
	glGenTextures(1, &ID);
	glBindTexture(target, ID);

	glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


	glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_REPEAT);


	glTexImage2D(target, 0, GL_RGBA8, m_width, m_height, NULL, GL_RGBA, GL_UNSIGNED_BYTE, image);


	
	stbi_image_free(image);
}


Engine::Math::Vec2f OpenGLTexture::GetSize() const
{
	
	return Engine::Math::Vec2f(m_width,m_height);
}

void OpenGLTexture::Bind(unsigned slot) const
{
	assert(slot >= 0 && slot <= 31);

	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(target, ID);
}

OpenGLTexture::~OpenGLTexture()
{
	glDeleteTextures(1, &ID);
}
