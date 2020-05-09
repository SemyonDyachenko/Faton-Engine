#ifndef ENGINE_ANIMATION_COMPONENT_H
#define ENGINE_ANIMATION_COMPONENT_H


#include <map>
#include <string>
#include <vector>

#include "../../Core/Core.h"

#include "../../Math/Rect.hpp"
#include "../../renderer/Texture.h"
#include "Component.h"


namespace Engine
{

	class Animation
	{
	public:
		std::vector<std::shared_ptr<Texture2D>>& m_Textures;
		float m_AnimationSpeed, m_CurrentFrame = 0;
		bool m_Flip, m_Playing, m_Loop;

		Animation(std::vector<std::shared_ptr<Texture2D>>& textures, float animationSpeed) : m_Textures(textures), m_AnimationSpeed(animationSpeed)
		{
			m_Playing = false;
			m_Flip = false;
			m_Loop = false;
		}

		~Animation()
		{

		}

		void OnUpdate(float DeltaTime)
		{
			if (m_Playing)
			{

				m_CurrentFrame += m_AnimationSpeed * DeltaTime;

				if (m_CurrentFrame > m_Textures.size())
				{
					m_CurrentFrame -= m_Textures.size();
					if (!m_Loop) {
						m_Playing = false;
					}
				}
			}
		}
		
		std::shared_ptr<Texture2D>& GetNowFrame()
		{
			if (m_Textures[static_cast<int>(m_CurrentFrame)] == NULL)
			{
				FATON_PRINT("ANIMATION: Textures empty frame");
			}
			else
			{
				return m_Textures[static_cast<int>(m_CurrentFrame)];
			}
		}

		void Play()
		{
			m_Playing = true;
		}

		void Pause()
		{
			m_Playing = false;
		}

		bool IsPlaying()
		{
			return m_Playing;
		}
	};


	class AnimationComponent : public Component
	{
	public:
		AnimationComponent();

		virtual ~AnimationComponent();
		
		void OnUpdate(float DeltaTime) override;

		void AddAnimation(std::string& name, Animation* anim);

		void SetAnimation(std::string& name);

		void Play(std::string& name);

		void Pause();

		bool IsPlaying();

		void Destroy() override;

		std::shared_ptr<Texture2D>& GetNowTextureFrame();

	private:
		std::string m_CurrentAnimation;
		std::map<std::string, Animation*> m_Animations;
	};

}

#endif 