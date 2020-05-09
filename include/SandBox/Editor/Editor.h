#ifndef ENGINE_EDITOR_H
#define ENGINE_EDITOR_H


#include "../../Engine/Engine.h"
#include "../GUI/Widget.h"

class Editor
{
public:
	Editor(float window_width,float window_height);
	
	virtual ~Editor();


	void OnUpdate(float deltaTime);

	void OnRender();
private:
	void InitWidgets();

	Engine::Camera2D* m_Camera;

	Widget* MapOpenWidget;
};


#endif 