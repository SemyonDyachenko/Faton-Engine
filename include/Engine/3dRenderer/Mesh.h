#ifndef ENGINE_MESH_H
#define ENGINE_MESH_H
#include "../Math/Math.h"
#include "Drawable3D.h"
#include "../renderer/VertexArray.h"


namespace Engine
{

	
	class Mesh 
	{

	public:
		Mesh(std::vector<float> vertices,std::vector<unsigned int> indices);

		explicit Mesh(const Mesh* mesh);

		virtual ~Mesh();

		void OnRender();
		
	private:
		std::shared_ptr<VertexArray> m_VertexArray;
	

		std::vector<float> m_VertexBuffer;
		std::vector<unsigned int> m_IndexBuffer;
		
	};
	
}



#endif