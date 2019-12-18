//
// Created by semyon on 02.12.2019.
//


#include "../../../include/Engine/renderer/RendererAPI.h"
#include "../../../platform/SFML/SFMLRendererAPI.h"
#include "../../../platform/OpenGL/OpenGLRendererAPI.h"


namespace Engine {

    RendererAPI::API RendererAPI::m_API  = RendererAPI::API::OPENGL;

    RendererAPI::API RendererAPI::getAPI() {
        return m_API;
    }

    std::unique_ptr<RendererAPI> RendererAPI::Create() {
        switch (m_API) {
            case RendererAPI::API::NONE: FATON_ERROR_01;
            case RendererAPI::API::OPENGL: return std::make_unique<OpenGLRendererAPI>();
            case RendererAPI::API::SFML: return std::make_unique<SFMLRendererAPI>();
        }
        return nullptr;
    }



}