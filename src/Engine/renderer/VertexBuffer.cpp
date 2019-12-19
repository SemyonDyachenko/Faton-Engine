//
// Created by semyon on 17.12.2019.
//

#include "../../../include/Engine/renderer/VertexBuffer.h"
#include "../../../include/Engine/renderer/RendererAPI.h"
#include "../../../platform/OpenGL/OpenGLVertexBuffer.h"

namespace Engine {

    std::shared_ptr<VertexBuffer> Engine::VertexBuffer::Create(float *data, unsigned int size) {
        switch (RendererAPI::getAPI()) {
            case RendererAPI::API::NONE:
                FATON_ERROR_01;
            case RendererAPI::API::OPENGL:
                return std::make_shared<OpenGLVertexBuffer>(data, size);
        }
    }


}
