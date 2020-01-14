//
// Created by semyon on 02.12.2019.
//

#ifndef MY_OWN_GAME_RENDERERAPI_H
#define MY_OWN_GAME_RENDERERAPI_H


#include "../Core/Window.h"
#include "VertexArray.h"
#include <memory>



namespace Engine {

    class RendererAPI {
    public:
        enum class API {
            NONE = 0,
            OPENGL = 1,
            SFML = 2,
        };

    private:
        static API m_API;
    public:


        virtual void Init() = 0;

        virtual void Clear(Math::Color3<float>& color) = 0;

		virtual void SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) = 0;

        virtual void Clear(Window& window) = 0; // for sfml

        virtual void Draw(VertexArray* vertexArray) = 0;

        inline static API getAPI()
        {
            return m_API;
        }

        static std::unique_ptr<RendererAPI> Create();

    };


}


#endif //MY_OWN_GAME_RENDERERAPI_H
