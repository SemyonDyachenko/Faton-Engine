//
// Created by semyon on 01.12.2019.
//

#ifndef MY_OWN_GAME_APPLICATION_H
#define MY_OWN_GAME_APPLICATION_H


#include "../../../include/Engine/Engine.h"
#include "../../../include/Engine/Entity/Entity.h"

using namespace Engine;
using namespace Math;
using namespace Physics;


class Application {
private:
    std::unique_ptr<Window> window;


	std::shared_ptr<Shader> m_Shader;

	Vec4f m_Color =  { 0.2f, 0.3f, 0.8f, 1.0f };

	Camera2D * camera;
	
    Event* event;

	Sprite *sprite;
	Sprite * sprite2;

    bool is_Running = true;
	Entity::Entity * entity;
	
	MovementComponent * component;

	
	
	void InitGraphics();
public:
    Application();
    virtual ~Application();


	
    void OnUpdate();
    void OnRender();
    void Run();
};


#endif //MY_OWN_GAME_APPLICATION_H
