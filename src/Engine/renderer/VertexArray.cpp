//
// Created by semyon on 17.12.2019.
//



#include "../../../include/Engine/renderer/VertexArray.h"
#include "../../../include/Engine/renderer/Renderer2D.h"
#include "../../../include/Engine/Core/Core.h"
#include "../../../platform/OpenGL/OpenGLVertexArray.h"

namespace Engine
{


    std::shared_ptr<Engine::VertexArray> Engine::VertexArray::Create()
    {
        switch(Engine::RendererAPI::getAPI()) {

            case RendererAPI::API::NONE: FATON_ERROR_01;
            case RendererAPI::API::OPENGL : return std::make_shared<OpenGLVertexArray>();
        }

        return nullptr;
    }

}