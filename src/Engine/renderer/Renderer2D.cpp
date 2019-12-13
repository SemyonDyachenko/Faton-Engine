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

    void Renderer2D::DrawRect(Engine::Math::Vector2<float> &positions, Engine::Math::Vector2<float> &size,Engine::Math::Color3<float> &color3)
    {
       //return Engine::Sprite()

    }

    void Renderer2D::RendererDraw(Sprite &sprite, Window &window) {
       // sprite.Draw(window);
    }

    void Renderer2D::RendererDraw(Sprite &sprite, Window &window, Shader &shader) {

    }

    // void Renderer2D::Draw(Engine::Drawable object, Window &window) {
    //    window.Draw(object);
  //  }



    //   void Renderer2D::Draw(Engine::Drawable object) {
//
 //   }

    //void Renderer2D::Draw(Engine::Drawable object) {
   //     object.Draw();
   // }


}