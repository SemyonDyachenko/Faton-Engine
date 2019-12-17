//
// Created by semyon on 11.12.2019.
//

#include "SFMLShader.h"


SFMLShader::SFMLShader() {

}

SFMLShader::SFMLShader(const char *vertex_shader_file, const char *fragment_shader_file) {
    this->shader.loadFromFile(vertex_shader_file,fragment_shader_file);
}

SFMLShader::SFMLShader(const char *vertex_shader_file, const char *fragment_shader_file,
                       const char *geometry_shader_file) {
    this->shader.loadFromFile(vertex_shader_file,fragment_shader_file,geometry_shader_file);
}

SFMLShader::~SFMLShader() {

}



void SFMLShader::LoadFromFile(const char *vertex_shader_file, const char *fragment_shader_file) {
this->shader.loadFromFile(vertex_shader_file,fragment_shader_file);
}


void SFMLShader::LoadFromFile(const char *vertex_shader_file, const char *fragment_shader_file,
                              const char *geometry_shader_file) {
this->shader.loadFromFile(vertex_shader_file,fragment_shader_file,geometry_shader_file);
}


void SFMLShader::Bind() {
sf::Shader::bind(&this->shader);
}

std::unique_ptr<Engine::Shader> Engine::Shader::Create() {
    return std::make_unique<SFMLShader>();
}

