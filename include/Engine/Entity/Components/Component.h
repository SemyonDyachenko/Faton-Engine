#ifndef ENGINE_COMPONENT_H
#define ENGINE_COMPONENT_H


namespace Engine
{

	class Component
	{
		friend class Entity;
	public:
		virtual ~Component() = default;

		virtual void OnUpdate(float DeltaTime) = 0;
		virtual void Destroy() = 0;
	};
	
}


#endif