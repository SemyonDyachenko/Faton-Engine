#ifndef ENGINE_OPENGL_TEXT_H
#define ENGINE_OPENGL_TEXT_H


#include "../../include/Engine/Core/Text.h"

#include "OpenGLShader.h"

#include <GL/glew.h>
#include <map>

struct Character
{
	GLuint TexID;
	Engine::Math::Vec2i Size;
	Engine::Math::Vec2i Bearing;
	GLuint Advance;
};

class glText : public Engine::Text
{
public:
	glText(GLuint width, GLuint height);

	void Load(std::string font, unsigned characterSize) override;

	void RenderText(std::string text, float x, float y, float scale, Engine::Math::Color3f color) override;

	OpenGLShader *TextShader;
		
	virtual ~glText();

	std::map<GLchar, Character> m_Characters;

private:
	GLuint VAO, VBO;
};


#endif