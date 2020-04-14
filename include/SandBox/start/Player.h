#include <iostream>

#include "../../Engine/Engine.h"


class Player {

public:
	Player(std::string texturePath);

	~Player();

	void OnUpdate(float DT);

	Engine::Sprite& GetSprite();

	Engine::Entity::Entity& GetEntity();

	void OnRender(Engine::Camera2D& camera);

private:
	enum class MovementStates
	{
		IDLE = 0,
		JUMP,
		WALK_RIGHT,
		WALK_LEFT
	};
	MovementStates state;

	Engine::Entity::Entity* entity;

	Engine::Sprite* sprite;
	std::shared_ptr<Engine::Texture2D> texture;

	float x, y;
	
	Engine::Physics::BoxCollider2D* collider;

	Engine::MovementComponent* movComponent;
	Engine::AnimationComponent* animComponent;
	std::map<std::string, Engine::Animation*> animations;
	std::vector<std::shared_ptr<Engine::Texture2D>> textures;
	std::vector<std::shared_ptr<Engine::Texture2D>> textures1;
	Engine::Animation* leftAnim;
	Engine::Animation* rightAnim;
	Engine::Animation* jump;

};