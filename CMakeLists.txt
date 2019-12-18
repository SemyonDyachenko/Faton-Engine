cmake_minimum_required(VERSION 3.14)
project(my_own_game)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR 'lib/SFML-2.5.1/include')
set(SFML_LIBRARY_DIR "lib/SFML-2.5.1/lib")

set(IMGUI_DEMO_SOURCES  lib/imgui/imgui.cpp lib/imgui/imgui-SFML.cpp lib/imgui/imgui_draw.cpp lib/imgui/imgui_widgets.cpp src/Engine/Camera/Camera.cpp include/Engine/Camera/Camera.h src/SandBox/start/Application.cpp include/SandBox/start/Application.h src/Engine/Object/Scene.cpp include/Engine/Object/Scene.h src/Engine/renderer/Renderer2D.cpp include/Engine/renderer/Renderer2D.h src/Engine/renderer/RendererAPI.cpp include/Engine/renderer/RendererAPI.h include/Engine/Math/Vector2.hpp include/Engine/Core/Core.h src/Engine/renderer/Sprite.cpp include/Engine/renderer/Sprite.h platform/SFML/SFMLRendererAPI.h platform/SFML/SFMLRendererAPI.cpp platform/Window/SFMLWindow.cpp platform/Window/SFMLWindow.h  include/Engine/Core/Window.h include/Engine/Math/Matrix.hpp include/Engine/Events/Event.h include/Engine/Math/Color3.hpp src/Engine/Physics/BoxCollider2D.cpp include/Engine/Physics/BoxCollider2D.h platform/SFML/SFMLSprite.cpp platform/SFML/SFMLSprite.h  include/Engine/Math/Vector3.hpp include/Engine/Math/Vector3.hpp src/Engine/Physics/Collider2D.cpp include/Engine/Physics/Collider2D.h src/Engine/Events/AppEvent.cpp include/Engine/Events/AppEvent.h include/Engine/Core/EngineKeys.h src/Engine/Engine.cpp include/Engine/Engine.h src/Engine/renderer/Drawable.cpp include/Engine/renderer/Drawable.h include/Engine/Core/Timer.h src/Engine/renderer/Shader.cpp include/Engine/renderer/Shader.h platform/SFML/SFMLShader.cpp platform/SFML/SFMLShader.h src/Engine/Physics/Collision.cpp include/Engine/Physics/Collision.h include/Engine/Core/Input.h platform/SFML/SFMLInput.h platform/SFML/SFMLInput.cpp platform/Window/GLFWWindow.cpp platform/Window/GLFWWindow.h platform/OpenGL/OpenGLRendererAPI.cpp platform/OpenGL/OpenGLRendererAPI.h platform/OpenGL/OpenGLShader.cpp platform/OpenGL/OpenGLShader.h platform/OpenGL/OpenGLVertexArray.cpp platform/OpenGL/OpenGLVertexArray.h include/Engine/renderer/VertexArray.h include/Engine/renderer/IndexBuffer.h include/Engine/renderer/VertexBuffer.h src/Engine/renderer/VertexBuffer.cpp src/Engine/renderer/IndexBuffer.cpp src/Engine/renderer/VertexArray.cpp include/Engine/Math/Math.h)

find_package(OpenGL)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)


if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()



add_executable(my_own_game src/SandBox/start/main.cpp ${IMGUI_DEMO_SOURCES})

target_link_libraries (my_own_game sfml-graphics sfml-window sfml-system  ${OPENGL_gl_LIBRARY})
