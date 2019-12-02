//
// Created by semyon on 02.12.2019.
//

#ifndef MY_OWN_GAME_RENDERERAPI_H
#define MY_OWN_GAME_RENDERERAPI_H


class RendererAPI {

public:
    enum class API
    {
        NONE = 0,
        OPENGL = 0,
        SFML = 1,
        VULKAN = 0,
        DIRECTX = 0
    };

    virtual void Init() = 0;
    virtual void SetClearColor(const glm::vec4 color) = 0;
    virtual void Clear() = 0;

    static API getAPI() {
        return m_API;
    }
private:
    static API m_API;
};


#endif //MY_OWN_GAME_RENDERERAPI_H
