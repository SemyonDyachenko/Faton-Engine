#include <vector>
#include "../renderer/VertexArray.h"
#ifndef ENGINE_MESH_H
#define ENGINE_MESH_H



namespace Engine
{

	class Mesh
	{
	public:
		Mesh(std::vector<float> vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
		
		virtual ~Mesh();

		void Bind();
	private:
		std::shared_ptr<Engine::VertexArray> vao;

	};



}



#endif