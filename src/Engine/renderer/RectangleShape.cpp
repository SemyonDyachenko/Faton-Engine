#include "..\..\..\include\Engine\renderer\RectangleShape.h"


namespace Engine
{


	Rectangle::Rectangle(float x, float y, float width, float height)
	{
		m_Position = { x,y,0 };

		m_Size = { width,height };

		m_Transform = translate(glm::mat4(1.0f), { m_Position.x,m_Position.y,m_Position.z }) * scale(glm::mat4(1.0f), { m_Size.x, m_Size.y, 1.0f });

		vao = VertexArray::Create();


		std::vector<float> vertices =
		{
		 0.5f,  0.5f, 0.0f,  1.0f, 1.0f, // top right
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,  0.f, 0.f,   // bottom left
		-0.5f,  0.5f, 0.0f,  0.0f, 1.f    // top left 
		};

		std::vector<unsigned int> indices =
		{
			0, 1, 2,
			2, 3, 0
		};

	
		

		vao->AddVertexBuffer(vertices);
		vao->AddIndexBuffer(indices);

	}

	Rectangle::~Rectangle()
	{
	}

	void Rectangle::SetPosition(float x, float y)
	{
		m_Position = { x,y,0 };
		m_Transform = translate(glm::mat4(1.0f), { m_Position.x,m_Position.y,m_Position.z }) * scale(glm::mat4(1.0f), { m_Size.x, m_Size.y, 1.0f });

	}

	void Rectangle::SetSize(float w, float h)
	{
		m_Size = { w,h };

		m_Transform = translate(glm::mat4(1.0f), { m_Position.x,m_Position.y,m_Position.z }) * scale(glm::mat4(1.0f), { m_Size.x, m_Size.y, 1.0f });
	}


	const glm::mat4 & Rectangle::GetTransform() const
	{
		return m_Transform;
	}

	void Rectangle::Draw() const
	{
		vao->GetDrawable()->Bind();
		vao->GetDrawable()->Draw();
	}


}