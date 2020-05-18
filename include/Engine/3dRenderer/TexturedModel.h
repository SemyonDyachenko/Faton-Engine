#ifndef ENGINE_TEXTURE_MODEL_H
#define ENGINE_TEXTURE_MODEL_H

#include "Mesh.h"
#include "../renderer/Texture.h"

namespace Engine
{
	class TexturedModel {

	public:
		TexturedModel(Mesh* mesh, std::shared_ptr<Texture2D> texture);

		Mesh& GetMesh() const;
		std::shared_ptr<Texture2D> GetTexture() const;


	private:
		Mesh* m_Mesh;
		std::shared_ptr<Texture2D> m_Texture;

	};


}



#endif