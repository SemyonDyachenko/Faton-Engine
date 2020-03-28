#ifndef ENGINE_ANIMATION_COMPONENT_H
#define ENGINE_ANIMATION_COMPONENT_H


#include <map>
#include <string>
#include <vector>



#include "../../Math/Rect.hpp"
#include "../../renderer/Texture.h"
#include "Component.h"


namespace Engine
{

	class AnimationComponent : public Component
	{
	public:
		AnimationComponent();

		virtual ~AnimationComponent();
		
		void OnUpdate(float DeltaTime) override;

		void Destroy() override;

	private:
		std::string XmlFilePath;

		class Animation
		{
		public:
			std::vector<std::shared_ptr<Texture2D>>& m_Textures;
			float m_AnimationSpeed;
		
			Animation(std::vector<std::shared_ptr<Texture2D>>& textures,float animationSpeed) : m_Textures(textures), m_AnimationSpeed(animationSpeed)
			{
				
			}

			void Play()
			{
				while(true)
				{
					for(int )
				}
			}
			void Pause()
			{
				
			}
			void Reset()
			{
				
			}
		};

		std::map<std::string, Animation> m_Animations;
	};

}

#endif 