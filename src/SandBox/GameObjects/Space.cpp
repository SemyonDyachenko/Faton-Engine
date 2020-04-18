#include "..\..\..\include\SandBox\GameObjects\Space.h"

//DEMO

SpaceArea::SpaceArea(float aspectRatio, float rocketX, float rocketY)
{
	m_Camera = new Engine::Camera2D(aspectRatio);

	AnimationSpeed = 0.07f;




	m_RightAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test3/Fly 1.png"));
	m_RightAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test3/Fly 2.png"));
	m_RightAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test3/Fly 1.png"));;
	m_RightAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test3/Fly 2.png"));
	m_RightAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test3/Fly 1.png"));



	m_TopAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-00.png"));
	m_TopAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-01.png"));
	m_TopAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-02.png"));
	m_TopAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-03.png"));
	m_TopAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-04.png"));
	m_TopAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-05.png"));

	m_BottomAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-00.png"));
	m_BottomAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-01.png"));
	m_BottomAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-02.png"));
	m_BottomAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-03.png"));
	m_BottomAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-04.png"));
	m_BottomAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test/right/adventurer-run-05.png"));

	
	

	startRocketTexture = Engine::Texture2D::Create("assets/images/milana.jpg");

	
	m_RocketMovementComponent = new Engine::MovementComponent(*m_RocketSpriteComponent,0.3f,0.015f);
	m_RocketAnimationComponent = new Engine::AnimationComponent();


	m_MoveTopAnimation = new Engine::Animation(m_TopAnimationTextures, AnimationSpeed);
	m_MoveBottomAnimation = new Engine::Animation(m_BottomAnimationTextures, AnimationSpeed);
	m_MoveRightAnimation = new Engine::Animation(m_RightAnimationTextures, AnimationSpeed);

	m_TopAnimName = "TOP";
	m_BottomAnimName = "BOTTOM";
	m_RightAnimName = "RIGHT";

	m_RocketAnimationComponent->AddAnimation(m_RightAnimName, m_MoveRightAnimation);
	m_RocketAnimationComponent->AddAnimation(m_TopAnimName, m_MoveTopAnimation);
	m_RocketAnimationComponent->AddAnimation(m_BottomAnimName, m_MoveBottomAnimation);

	m_RocketAnimationComponent->SetAnimation(m_RightAnimName);

	m_RocketSpriteComponent = new Engine::Sprite(startRocketTexture);


	m_RocketCharacter = new RocketMainCharacter(2, 2);
	m_RocketCharacter->AddSpriteComponent(m_RocketSpriteComponent);
	m_RocketCharacter->AddMovementComponent(m_RocketMovementComponent);
	m_RocketCharacter->AddAnimationCompoment(m_RocketAnimationComponent);
	m_RocketCharacter->AddBoxColliderComponent();

	m_RocketCharacter->GetSprite()->TransformRecalculate();
	m_RocketCharacter->GetSprite()->TextureRecalculate();


	
}

SpaceArea::~SpaceArea()
{
	
}
  
void SpaceArea::Update(float DeltaTime)
{

	m_Camera->Update(DeltaTime);

	m_RocketCharacter->OnUpdate(DeltaTime);
	m_RocketMovementComponent->OnUpdate(DeltaTime);
	m_RocketAnimationComponent->OnUpdate(DeltaTime);

	m_RocketCharacter->GetSprite()->ChangeTexture(m_RocketAnimationComponent->GetNowTextureFrame());
	m_RocketCharacter->AddBoxColliderComponent();


	//m_Camera->SetPosition({ m_RocketCharacter->GetSprite()->GetPosition().x,m_Camera->GetPosition().y,0 });

	m_RocketCharacter->GetSprite()->SetSize({ 2,1.5 });

	


	if (Engine::Input::IsKeyPressed(FATON_KEY_T))
	{
		m_RocketCharacter->Move(0.0f, 0.05f, DeltaTime);
	}
	else if (Engine::Input::IsKeyPressed(FATON_KEY_G))
	{
		m_RocketCharacter->Move(0.0f, -0.05f, DeltaTime);
	}
	else  if (Engine::Input::IsKeyPressed(FATON_KEY_H))
	{
		m_RocketCharacter->Move(0.02f, 0.0f, DeltaTime);
		m_RocketAnimationComponent->SetAnimation(m_RightAnimName);
		m_RocketAnimationComponent->Play(m_RightAnimName);


	}




}

void SpaceArea::Render()
{


	//Engine::Renderer2D::DrawRect(*m_Camera, { 10.0f,-8 }, { 1920,1080 }, { 0,0,0,1 });


	m_RocketCharacter->OnRender(*m_Camera);
}
