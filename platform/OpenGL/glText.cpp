#include "glText.h"

#include <glm/gtc/matrix_transform.hpp>


glText::glText(GLuint width, GLuint height)
{
	this->TextShader =new OpenGLShader("assets/shaders/text.vs", "assets/shaders/text.vs");
	this->TextShader->SetMat4("projection", glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f));
	this->TextShader->SetInt("text", 0);

	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &this->VBO);
	glBindVertexArray(this->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

glText::~glText()
{
}

void glText::Load(std::string font, unsigned characterSize)
{
	this->m_Characters.clear();

	
}

void glText::RenderText(std::string text, float x, float y, float scale, Engine::Math::Color3f color)
{
}


