#ifndef ENGINE_SHAPE_H
#define ENGINE_SHAPE_H




namespace Engine
{

	class Shape
	{
	public:
		virtual ~Shape() = default;
		
		virtual void Draw() const = 0;
	};
	
}







#endif