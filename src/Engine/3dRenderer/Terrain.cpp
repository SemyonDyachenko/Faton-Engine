#include "..\..\..\include\Engine\3dRenderer\Terrain.h"


namespace Engine {

	Terrain::Terrain(int gridX, int gridZ, std::shared_ptr<Texture2D>& texture)
	{
		m_Texture = texture;
		this->x = gridX * this->size;
		this->z = gridZ * this->size;

		this->shader = Shader::Create("Shaders/3D/terrainVertexShader.glsl","Shaders/terrainFragmentShader.glsl");

	}

	Terrain::~Terrain()
	{

	}

	void Terrain::Render(Camera3D &camera)
	{
		shader->Bind();

		shader->SetMat4("ViewProjectionMatrix", camera.GetViewProjectionMatrix());

		//shader->SetInt("m_Texture", 0);

		//m_Texture->Bind();



		shader->Unbind();
	}


}