//
// Created by semyon on 02.12.2019.
//

#include "../../../include/Engine/renderer/Renderer2D.h"


namespace Engine
{

    std::unique_ptr<RendererAPI> RenderCommand::m_RendererAPI = RendererAPI::Create();

    Renderer2D::Renderer2D() {

    }

    Renderer2D::~Renderer2D() {

    }

    void Renderer2D::Init() {

    }

    void Renderer2D::createScene(Engine::Camera &camera) {

    }

    void Renderer2D::endScene() {

    }


}