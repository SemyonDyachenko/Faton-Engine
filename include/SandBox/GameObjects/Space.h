#ifndef GAME_SPACE_H
#define GAME_SPACE_H


#include "RocketMainCharacter.h"

class SpaceArea
{
public:
	SpaceArea(float aspectRatio,float rocketX,float rocketY);

	~SpaceArea();

	void Update(float DeltaTime);

	void Render();
private:
	RocketMainCharacter* m_RocketCharacter;

	Engine::AnimationComponent* m_RocketAnimationComponent;
	Engine::MovementComponent* m_RocketMovementComponent;
	Engine::Sprite* m_RocketSpriteComponent;

	Engine::Animation *m_MoveTopAnimation;
	Engine::Animation* m_MoveBottomAnimation;
	Engine::Animation* m_MoveRightAnimation;

	Engine::Camera2D* m_Camera;
};


#endif