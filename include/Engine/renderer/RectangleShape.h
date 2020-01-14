#ifndef ENGINE_RECTANGLE_SHAPE_H
#define ENGINE_RECTANGLE_SHAPE_H


#include <glm/glm.hpp>

#include "VertexArray.h"
#include "Shape.h"
#include "../Math/Math.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Engine
{

	class Rectangle : public Shape
	{
	public:
		Rectangle(float x, float y, float width, float height);

		virtual ~Rectangle();

		const glm::mat4& GetTransform() const;
		
		void Draw() const override;


	private:
		std::shared_ptr<VertexArray> vao;

		glm::mat4 m_Transform;
		Math::Vec3f m_Position;
		Math::Vec2f m_Size;

		Math::Color3f m_Color;
	};
	
}



#endif