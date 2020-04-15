#ifndef ENGINE_OPENGL_TEXT_H
#define ENGINE_OPENGL_TEXT_H


#include <ft2build.h>
#include FT_FREETYPE_H


#include "../../include/Engine/Core/Text.h"

#include "OpenGLShader.h"
#include <map>

struct Character {
    GLuint TextureID;   
    glm::ivec2 Size;    
    glm::ivec2 Bearing; 
    GLuint Advance;     
};




class glText : public Engine::Text 
{
public:
    
    std::map<GLchar, Character> Characters;
    
    OpenGLShader *TextShader;
    
    glText(GLuint width, GLuint height);

    void IsStatic(bool staticVal) override;
   
    void Load(std::string font, GLuint fontSize) override;
    
    void RenderText(const glm::mat4& projection,std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color = glm::vec3(1.0f)) override;
private:
    
    bool m_IsStatic = true; 

    GLuint VAO, VBO;
};


#endif