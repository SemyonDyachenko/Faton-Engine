//
// Created by semyon on 08.12.2019.
//

#ifndef MY_OWN_GAME_ENGINE_H
#define MY_OWN_GAME_ENGINE_H

//----------Camera------------
#include "Camera/Camera.h"
#include "Camera/Camera3D.h"

//-------------Core-----------
#include "Core/Core.h"
#include "Core/Window.h"
#include "Core/EngineKeys.h"
#include "Core/Timer.h"
#include "Core/Input.h"
#include "Events/Event.h"
#include "Events/AppEvent.h"
#include "Core/Text.h"

//---------Math--------------
#include "Math/Vector2.hpp"
#include "Math/Vector3.hpp"
#include "Math/Vector4.hpp"
#include "Math/Math.h"
#include "Math/Matrix.hpp"
#include "Math/Color3.hpp"
#include "Math/Rect.hpp"


//---------Renderer---------
#include "renderer/Renderer2D.h"
#include "renderer/RendererAPI.h"
#include "renderer/Sprite.h"
#include "renderer/Shader.h"
#include "renderer/Texture.h"
#include "renderer/VertexArray.h"
#include "renderer/RectangleShape.h"
#include "renderer/Drawable.h"
#include "renderer/Drawable2D.h"
#include "renderer/Drawable3D.h"
#include "renderer/Mesh.h"
#include "renderer/Shape.h"
#include "renderer/TextureHolder.h"

//-------Physics Engine --------
#include "Physics/Collider2D.h"
#include "Physics/BoxCollider2D.h"
#include "Physics/Collision.h"
#include "Physics/World.h"
#include "Physics/RigidBody.h"


//----PLATFORM----------------
#ifdef FATON_WINDOWS_PLATFORM
#include <Windows.h>
#endif

//---ENTITY------------------
#include "Entity/Entity.h"
#include "Entity/Scene.h"
#include "Entity/Scene2D.h"
#include "Entity/Scene3D.h"
#include "Entity/Components/AnimationComponent.h"
#include "Entity/Components/Component.h"
#include "Entity/Components/MovementComponent.h"

#endif //MY_OWN_GAME_ENGINE_H
