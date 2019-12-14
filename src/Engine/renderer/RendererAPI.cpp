//
// Created by semyon on 02.12.2019.
//


#include "../../../include/Engine/renderer/RendererAPI.h"
#include "../../../platform/SFML/SFMLRendererAPI.h"



namespace Engine {

    RendererAPI::API RendererAPI::m_API  = RendererAPI::API::SFML;

    RendererAPI::API RendererAPI::getAPI() {
        return m_API;
    }

    std::unique_ptr<RendererAPI> RendererAPI::Create() {
        switch (m_API) {
            case RendererAPI::API::NONE: std::cout << "Not use API!" << std::endl;
            case RendererAPI::API::OPENGL: std::cout << "Opengl while not support! " << std::endl;
            case RendererAPI::API::SFML: return std::unique_ptr<SFMLRendererAPI>();
        }
        return nullptr;
    }



}