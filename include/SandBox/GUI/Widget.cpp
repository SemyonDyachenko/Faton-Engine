#include "Widget.h"



Widget::Widget(float x, float y, float w, float h)
{
	
}

Widget::~Widget()
{
	delete m_BoundsSprite;
}

void Widget::SetPositon(float x, float y)
{
	m_Position = { x,y };
}

void Widget::SetSize(float w, float h)
{
	m_Size = { w,h };
}

void Widget::OnUpdate(float DeltaTime)
{

}

void Widget::OnRender(Engine::Camera2D& camera)
{
	m_BoundsSprite->OnRender(camera);
}
