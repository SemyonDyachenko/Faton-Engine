#ifndef GUI_WIDGET_H
#define GUI_WIDGET_H

#include "../../../include/Engine/Engine.h"

class Widget
{
public:
	Widget(float x,float y,float w,float h);

	~Widget();

	void SetPositon(float x, float y);

	void SetSize(float w, float h);

	void OnUpdate(float DeltaTime);

	void OnRender(Engine::Camera2D& camera);
private:
	Engine::Sprite* m_BoundsSprite;
	Engine::Math::Vec2f m_Size;
	Engine::Math::Vec2f m_Position;
};

#endif