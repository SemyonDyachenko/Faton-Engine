#include "..\..\..\..\include\Engine\Entity\Components\AnimationComponent.h"


namespace Engine
{


	AnimationComponent::AnimationComponent()
	{
	}

	AnimationComponent::~AnimationComponent()
	{
		m_Animations.clear();
	}

	void AnimationComponent::OnUpdate(float DeltaTime)
	{
		m_Animations[m_CurrentAnimation]->OnUpdate(DeltaTime);
	}

	void AnimationComponent::AddAnimation(std::string& name, Animation* anim)
	{
		m_Animations[name] = anim;
	}

	void AnimationComponent::SetAnimation(std::string& name)
	{
		m_CurrentAnimation = name;
	}

	void AnimationComponent::Play(std::string& name)
	{
		m_Animations[m_CurrentAnimation]->Play();
	}

	void AnimationComponent::Pause()
	{
		m_Animations[m_CurrentAnimation]->Pause();
	}

	bool AnimationComponent::IsPlaying()
	{
		return m_Animations[m_CurrentAnimation]->IsPlaying();
	}

	void AnimationComponent::Destroy()
	{
		m_Animations.clear();
	}

	std::shared_ptr<Texture2D>& AnimationComponent::GetNowTextureFrame()
	{
		return m_Animations[m_CurrentAnimation]->GetNowFrame();
	}


}