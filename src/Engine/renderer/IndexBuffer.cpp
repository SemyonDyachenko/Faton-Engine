//
// Created by semyon on 17.12.2019.
//

#include "../../../include/Engine/renderer/IndexBuffer.h"
#include "../../../include/Engine/renderer/RendererAPI.h"
#include "../../../platform/OpenGL/OpenGLIndexBuffer.h"


namespace Engine {

    std::shared_ptr<IndexBuffer> IndexBuffer::Create(unsigned int *data, unsigned int size) {
        switch (RendererAPI::getAPI()) {
            case RendererAPI::API::NONE:
                FATON_ERROR_01;
            case RendererAPI::API::OPENGL:
                return std::make_shared<OpenGLIndexBuffer>(data, size);
        }
    }

}