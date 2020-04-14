
#include "../../../include/SandBox/start/Player.h"


Player::Player(std::string texturePath)
{

	textures.push_back(Engine::Texture2D::Create("assets/images/anim/test/adventurer-run-00.png"));
	textures.push_back(Engine::Texture2D::Create("assets/images/anim/test/adventurer-run-01.png"));
	textures.push_back(Engine::Texture2D::Create("assets/images/anim/test/adventurer-run-02.png"));
	textures.push_back(Engine::Texture2D::Create("assets/images/anim/test/adventurer-run-03.png"));
	textures.push_back(Engine::Texture2D::Create("assets/images/anim/test/adventurer-run-04.png"));
	textures.push_back(Engine::Texture2D::Create("assets/images/anim/test/adventurer-run-05.png"));


	//components
	texture = Engine::Texture2D::Create(texturePath.c_str());
	
	movComponent = new Engine::MovementComponent(*sprite, 3.0f, 0.25f);
	animComponent = new Engine::AnimationComponent();
	
	leftAnim = new Engine::Animation(textures,0.01f);
	
	std::string left = "LEFT";

	animComponent->AddAnimation(left,leftAnim);
	animComponent->SetAnimation(left);

	sprite = new Engine::Sprite(2, 2, texture);

	//ENTITY
	entity = new Engine::Entity::Entity();
	entity->AddSpriteComponent(sprite);
	entity->AddMovementComponent(movComponent);
	entity->AddAnimationCompoment(animComponent);

}


Player::~Player()
{
	delete entity;
	delete sprite;
}

void Player::OnUpdate(float DT)
{
	entity->OnUpdate(DT);

	movComponent->OnUpdate(DT);
	animComponent->OnUpdate(DT);

	sprite->ChangeTexture(animComponent->GetNowTextureFrame());

	if (Engine::Input::IsKeyPressed(FATON_KEY_T))
	{
		entity->Move(0.0f, 0.1f, DT);
	}
	else if (Engine::Input::IsKeyPressed(FATON_KEY_G))
	{
		entity->Move(0.0f, -0.1f, DT);
	}
	else if (Engine::Input::IsKeyPressed(FATON_KEY_F))
	{
		entity->Move(-0.1f, 0.0f, DT);
	}
	else if (Engine::Input::IsKeyPressed(FATON_KEY_H))
	{
		entity->Move(0.02f, 0.0f,DT);
		std::string animnm = "LEFT";
		animComponent->Play(animnm);
	}

	
}

void Player::OnRender(Engine::Camera2D& camera)
{
	entity->OnRender(camera);
}
