//
// Created by semyon on 11.12.2019.
//

#ifndef MY_OWN_GAME_SFMLSHADER_H
#define MY_OWN_GAME_SFMLSHADER_H


#include <SFML/Graphics/Shader.hpp>
#include "../../include/Engine/renderer/Shader.h"

class SFMLShader : public Engine::Shader{
private:
    sf::Shader shader;

public:
    SFMLShader();

    SFMLShader(const char* vertex_shader_file,const char* fragment_shader_file);

    SFMLShader(const char* vertex_shader_file,const char* fragment_shader_file,const char* geometry_shader_file);

    ~SFMLShader();

    void LoadFromFile(const char* vertex_shader_file,const char* fragment_shader_file) override;

    void LoadFromFile(const char* vertex_shader_file,const char* fragment_shader_file,const char* geometry_shader_file) override;


    void Bind() override;
};


#endif //MY_OWN_GAME_SFMLSHADER_H
