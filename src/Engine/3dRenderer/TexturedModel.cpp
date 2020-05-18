#include "../../../include/Engine/3dRenderer/TexturedModel.h"


namespace Engine
{



	TexturedModel::TexturedModel(Mesh* mesh, std::shared_ptr<Texture2D> texture) 
		: m_Mesh(mesh),m_Texture(texture)
	{
	}

	Mesh& TexturedModel::GetMesh() const
	{
		return *m_Mesh;
	}

	std::shared_ptr<Texture2D> TexturedModel::GetTexture() const
	{
		return m_Texture;
	}

}