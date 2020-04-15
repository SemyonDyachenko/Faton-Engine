#ifndef ENGINE_OPENGL_TEXT_H
#define ENGINE_OPENGL_TEXT_H


#include <ft2build.h>
#include FT_FREETYPE_H


#include "../../include/Engine/Core/Text.h"

#include "OpenGLShader.h"
#include <map>

struct Character {
    GLuint TextureID;   // ID handle of the glyph texture
    glm::ivec2 Size;    // Size of glyph
    glm::ivec2 Bearing; // Offset from baseline to left/top of glyph
    GLuint Advance;     // Horizontal offset to advance to next glyph
};


// A renderer class for rendering text displayed by a font loaded using the 
// FreeType library. A single font is loaded, processed into a list of Character
// items for later rendering.
class glText : public Engine::Text 
{
public:
    // Holds a list of pre-compiled Characters
    std::map<GLchar, Character> Characters;
    // Shader used for text rendering
    OpenGLShader *TextShader;
    // Constructor
    glText(GLuint width, GLuint height);
    // Pre-compiles a list of characters from the given font
    void Load(std::string font, GLuint fontSize) override;
    // Renders a string of text using the precompiled list of characters
    void RenderText(Engine::Camera2D & camera,std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color = glm::vec3(1.0f)) override;
private:
    // Render state
    GLuint VAO, VBO;
};


#endif