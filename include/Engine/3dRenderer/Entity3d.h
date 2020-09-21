#ifndef ENGINE_ENTITY_3D
#define ENGINE_ENTITY_3D

#include "../renderer/Texture.h"
#include "../Math/Math.h"
#include "TexturedModel.h"

namespace Engine
{
	class Entity3d {
	
	public:
		Entity3d(TexturedModel* model, Math::Vec3f position, float rotatedX, float rotatedY, float rotatedZ, float scaleFactor);

		void Translate(float deltaX, float deltaY, float deltaZ);

		void Rotate(float deltaX, float deltaY, float deltaZ);

		TexturedModel & GetModel() const;

		void SetPosition(float x,float y,float z);

		Math::Vec3f GetPosition() const;

		void SetScaleFactor(float scaleFactor);

		float GetScaleFactor() const;

		void OnRender(Camera3D & camera);

		void TransformRecalculate();

		//void AddComponent(Component* component);

	private:
		TexturedModel* m_Model;
		Math::Vec3f m_Position;
		float m_RotatedX, m_RotatedY, m_RotatedZ;
		float m_ScaleFactor;

		std::shared_ptr<Shader> m_ViewShader;
		glm::mat4 m_Transform;

		//std::map<Component,std::string> m_Component;
	};


}




#endif