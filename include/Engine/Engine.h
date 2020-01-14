//
// Created by semyon on 08.12.2019.
//

#ifndef MY_OWN_GAME_ENGINE_H
#define MY_OWN_GAME_ENGINE_H

//----------Camera------------
#include "Camera/Camera.h"


//-------------Core-----------
#include "Core/Core.h"
#include "Core/Window.h"
#include "Core/EngineKeys.h"
#include "Core/Timer.h"
#include "Core/Input.h"
#include "Events/Event.h"
#include "Events/AppEvent.h"

//---------Math--------------
#include "Math/Vector2.hpp"
#include "Math/Vector3.hpp"
#include "Math/Vector4.hpp"
#include "Math/Math.h"
#include "Math/Matrix.hpp"
#include "Math/Color3.hpp"



//---------Renderer---------
#include "Object/Scene.h"
#include "Physics/Collider2D.h"
#include "Physics/BoxCollider2D.h"
#include "renderer/Renderer2D.h"
#include "renderer/RendererAPI.h"
#include "renderer/Sprite.h"
#include "renderer/Shader.h"
#include "renderer/Texture.h"
#include "renderer/VertexArray.h"
#include "renderer/RectangleShape.h"
#include "renderer/Drawable.h"


//----PLATFORM----------------
#ifdef FATON_WINDOWS_PLATFORM
#include <Windows.h>
#endif


#endif //MY_OWN_GAME_ENGINE_H
