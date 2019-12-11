//
// Created by semyon on 11.12.2019.
//

#ifndef MY_OWN_GAME_SHADER_H
#define MY_OWN_GAME_SHADER_H

namespace Engine {

    class Shader {
    public:
        ~Shader() = default;

        virtual void LoadFromFile(const char * vertex_shader_file,const char * fragment_shader_file) = 0;

        virtual void LoadFromFile(const char* vertex_shader_file,const char* fragment_shader_file,const char* geometry_shader_file) = 0;

        virtual void Bind() = 0;
    };


}

#endif //MY_OWN_GAME_SHADER_H
