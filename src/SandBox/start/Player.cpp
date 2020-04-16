
#include "../../../include/SandBox/start/Player.h"


Player::Player(std::string texturePath)
{

	textures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-00.png"));
	textures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-01.png"));
	textures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-02.png"));
	textures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-03.png"));
	textures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-04.png"));
	textures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-05.png"));

	textures1.push_back(Engine::Texture2D::Create("assets/images/anim/test/left/left0.png"));
	textures1.push_back(Engine::Texture2D::Create("assets/images/anim/test/left/left1.png"));
	textures1.push_back(Engine::Texture2D::Create("assets/images/anim/test/left/left2.png"));
	textures1.push_back(Engine::Texture2D::Create("assets/images/anim/test/left/left3.png"));
	textures1.push_back(Engine::Texture2D::Create("assets/images/anim/test/left/left4.png"));
	textures1.push_back(Engine::Texture2D::Create("assets/images/anim/test/left/left5.png"));


	//components
	texture = Engine::Texture2D::Create("assets/images/anim/test/left/left0.png");
	
	movComponent = new Engine::MovementComponent(*sprite, 3.0f, 0.25f);
	animComponent = new Engine::AnimationComponent();
	
	leftAnim = new Engine::Animation(textures,0.01f);
	rightAnim = new Engine::Animation(textures1,0.01f);

	std::string left = "LEFT";
	std::string right = "RIGHT";

	collider = new Engine::Physics::BoxCollider2D(sprite->GetBounds());

	animComponent->AddAnimation(left,leftAnim);
	animComponent->AddAnimation(right, rightAnim);

	animComponent->SetAnimation(left);

	sprite = new Engine::Sprite(2, 2, texture);
	
	

	//ENTITY
	entity = new Engine::Entity::Entity();
	entity->AddSpriteComponent(sprite);
	entity->AddMovementComponent(movComponent);
	entity->AddAnimationCompoment(animComponent);
	entity->AddBoxColliderComponent();

	entity->GetSprite()->SetSize({ 2.2,2 });
	entity->GetSprite()->TransformRecalculate();
	entity->GetSprite()->TextureRecalculate();
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
	entity->AddBoxColliderComponent();

	entity->GetSprite()->SetSize({ 2.2,2 });

	

	//entity->OnGravity(true);

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
		entity->Move(-0.02f, 0.0f, DT);
		std::string animnml = "RIGHT";
		animComponent->SetAnimation(animnml);
		animComponent->Play(animnml);
	}
	else if (Engine::Input::IsKeyPressed(FATON_KEY_H))
	{
		entity->Move(0.02f, 0.0f,DT);
		std::string animnm = "LEFT";
		animComponent->SetAnimation(animnm);
		animComponent->Play(animnm);
	}

	
}

Engine::Sprite& Player::GetSprite()
{
	return *sprite;
}

Engine::Entity::Entity& Player::GetEntity()
{
	return *entity;
}



void Player::OnRender(Engine::Camera2D& camera)
{
	entity->OnRender(camera);
}
