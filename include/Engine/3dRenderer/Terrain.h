#ifndef ENGINE_TERRAIN_H
#define ENGINE_TERRAIN_H

#include "Mesh.h"
#include "TexturedModel.h"

namespace Engine {

	class Terrain {
	public:
		Terrain(int gridX,int gridZ,std::shared_ptr<Texture2D>& texture);

		virtual ~Terrain();

		void Render(Camera3D & camera);
	private:
		const float size = 800;
		const int vertex_count = 128;

		float x;
		float z;

		Mesh * m_Mesh;
		std::shared_ptr<Texture2D> m_Texture;
		TexturedModel * m_Model;
		std::shared_ptr<Shader> shader;
	};

}


#endif