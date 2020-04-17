#ifndef GAME_SPACE_H
#define GAME_SPACE_H


#include "RocketMainCharacter.h"

#include "../ParticleSystem.h"

class SpaceArea
{
public:
	SpaceArea(float aspectRatio,float rocketX,float rocketY);

	~SpaceArea();

	void Update(float DeltaTime);

	void Render();
private:

	ParticleSystem *m_ParticleSystem;
	Props m_SmokeProps;

	float m_Time = 0.0f;
	float m_SmokeEmitInterval = 0.4f;
	float m_SmokeNextEmitTime = m_SmokeEmitInterval;

	Engine::Camera2D* m_Camera;

	RocketMainCharacter* m_RocketCharacter;

	Engine::AnimationComponent* m_RocketAnimationComponent;
	Engine::MovementComponent* m_RocketMovementComponent;
	Engine::Sprite* m_RocketSpriteComponent;

	float AnimationSpeed;

	std::shared_ptr<Engine::Texture2D> startRocketTexture;

	std::string m_TopAnimName;
	std::string m_BottomAnimName;
	std::string m_RightAnimName;

	std::vector<std::shared_ptr<Engine::Texture2D>> m_TopAnimationTextures;
	std::vector<std::shared_ptr<Engine::Texture2D>> m_BottomAnimationTextures;
	std::vector<std::shared_ptr<Engine::Texture2D>> m_RightAnimationTextures;


	Engine::Animation* m_MoveTopAnimation;
	Engine::Animation* m_MoveBottomAnimation;
	Engine::Animation* m_MoveRightAnimation;
};


#endif