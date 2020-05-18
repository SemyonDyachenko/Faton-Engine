#include "../../../include/Engine/3dRenderer/Mesh.h"



namespace Engine
{

	Mesh::Mesh(std::vector<float> vertices, std::vector<unsigned int> indices)
	{
		m_VertexArray = VertexArray::Create();
		m_IndexBuffer = indices;
		m_VertexBuffer = vertices;

		
		m_VertexArray->AddVertexBuffer(m_VertexBuffer);
		m_VertexArray->AddIndexBuffer(m_IndexBuffer);
		

	}

	Mesh::Mesh(const Mesh* mesh)
	{
		m_VertexArray = mesh->m_VertexArray;
	}



	Mesh::~Mesh()
	{
		
	}

	void Mesh::OnRender()
	{
		m_VertexArray->GetDrawable()->Bind();
		m_VertexArray->GetDrawable()->Draw();

	}


}
