#ifndef ENGINE_COMPONENT_H
#define ENGINE_COMPONENT_H


namespace Engine
{

	enum ComponentType
	{
		MOVEMENT_COMPONENT,
		TRANSFORMATION_COMPONENT,
		ANIMATION_COMPONENT
	};

	class Component
	{
	public:
		virtual ~Component() = default;

		virtual void OnUpdate(float DeltaTime) = 0;

		
		virtual void Destroy() = 0;
	};
	
}


#endif