#include "..\..\..\include\Engine\renderer\RectangleShape.h"

Engine::Rectangle::Rectangle(float x, float y, float width, float height)
{
	m_Position = { x,y,0 };

	m_Size = { width,height };

	m_Transform = glm::translate(glm::mat4(1.0f), { m_Position.x,m_Position.y,m_Position.z }) * glm::scale(glm::mat4(1.0f), { m_Size.x, m_Size.y, 1.0f });

	vao = Engine::VertexArray::Create();


	std::vector<float> vertices =
	{
	0.5f,  0.5f, 0.0f,    1.0f, 1.0f,   // top right
	 0.5f, -0.5f, 0.0f,     1.0f, 0.0f,   // bottom right
	-0.5f, -0.5f, 0.0f,     0.0f, 0.0f,   // bottom left
	-0.5f,  0.5f, 0.0f,      0.0f, 1.0f    // top left 
	};

	std::vector<unsigned int> indices =
	{
		0, 1, 2,
		2, 3, 0
	};


	vao->AddVertexBuffer(vertices);
	vao->AddIndexBuffer(indices);
			
}

Engine::Rectangle::~Rectangle()
{
}

const glm::mat4 & Engine::Rectangle::GetTransform() const
{
	return m_Transform;
}

void Engine::Rectangle::Draw() const
{
	vao->GetDrawable()->Bind();
	vao->GetDrawable()->Draw();
}
