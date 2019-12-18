//
// Created by semyon on 02.12.2019.
//


#include "../../../include/Engine/renderer/RendererAPI.h"
#include "../../../platform/SFML/SFMLRendererAPI.h"
#include "../../../platform/OpenGL/OpenGLRendererAPI.h"


namespace Engine {

    RendererAPI::API RendererAPI::m_API  = RendererAPI::API::OPENGL;

    std::unique_ptr<RendererAPI> RendererAPI::Create() {
        switch (m_API) {
            case RendererAPI::API::NONE: FATON_ERROR_01;
            case RendererAPI::API::OPENGL: return std::unique_ptr<OpenGLRendererAPI>();
            case RendererAPI::API::SFML: return std::unique_ptr<SFMLRendererAPI>();
        }
        return nullptr;
    }



}