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

    /*std::shared_ptr<RendererAPI> RendererAPI::Create() {
        switch (m_API)
        {
            case RendererAPI::API::NONE: std::cout << "Not use API!" << std::endl;
            case RendererAPI::API::SFML: return std::shared_ptr<SFMLRendererAPI>();
        }

        return nullptr;
    }*/


}