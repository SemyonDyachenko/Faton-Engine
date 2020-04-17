#include "..\..\..\include\SandBox\GameObjects\Space.h"

//DEMO

SpaceArea::SpaceArea(float aspectRatio, float rocketX, float rocketY)
{
	m_Camera = new Engine::Camera2D(aspectRatio);

	AnimationSpeed = 0.07f;

	m_ParticleSystem = new ParticleSystem();

	m_SmokeProps.Position = { 5.0f, 5.0f };
	m_SmokeProps.Velocity = { -2.0f,3.0f }, m_SmokeProps.VelocityVar = { 3.0f, 1.0f };
	m_SmokeProps.SizeBegin = 0.5f, m_SmokeProps.SizeEnd = 0.0f, m_SmokeProps.SizeVar = 0.3f;
	m_SmokeProps.ColorBegin = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
	m_SmokeProps.ColorEnd = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f , 1.0f };
	m_SmokeProps.LifeTime = 1.0f;


	m_RightAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test2/Asset 1.png"));
	m_RightAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test2/Asset 2.png"));
	m_RightAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test2/Asset 3.png"));;
	m_RightAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test2/Asset 4.png"));
	m_RightAnimationTextures.push_back(Engine::Texture2D::Create("assets/images/anim/test2/Asset 5.png"));



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
	m_Time += DeltaTime;

	m_Camera->Update(DeltaTime);

	m_RocketCharacter->OnUpdate(DeltaTime);
	m_RocketMovementComponent->OnUpdate(DeltaTime);
	m_RocketAnimationComponent->OnUpdate(DeltaTime);

	m_RocketCharacter->GetSprite()->ChangeTexture(m_RocketAnimationComponent->GetNowTextureFrame());
	m_RocketCharacter->AddBoxColliderComponent();


	m_Camera->SetPosition({ m_RocketCharacter->GetSprite()->GetPosition().x,m_Camera->GetPosition().y,0 });

	m_RocketCharacter->GetSprite()->SetSize({ 2,1.5 });

	m_ParticleSystem->OnUpdate(DeltaTime);


	if (Engine::Input::IsKeyPressed(FATON_KEY_T))
	{
		m_RocketCharacter->Move(0.0f, 0.1f, DeltaTime);
	}
	else if (Engine::Input::IsKeyPressed(FATON_KEY_G))
	{
		m_RocketCharacter->Move(0.0f, -0.1f, DeltaTime);
	}
	else  if (Engine::Input::IsKeyPressed(FATON_KEY_H))
	{
		glm::vec2 emissionPoint = { 0.0f, -0.6f };
		float rotation = glm::radians(0.02f * 4.0f - 90.0f);
		glm::vec4 rotated = glm::rotate(glm::mat4(1.0f), rotation, { 0.0f, 0.0f, 1.0f }) * glm::vec4(emissionPoint, 0.0f, 1.0f);

		m_SmokeProps.Position.x = m_RocketCharacter->GetSprite()->GetPosition().x + rotated.x;
		m_SmokeProps.Position.y = m_RocketCharacter->GetSprite()->GetPosition().y + rotated.y;
		m_SmokeProps.Velocity.y = 0.02f * 0.2f - 0.2f;
		m_ParticleSystem->Emit(m_SmokeProps);


		m_RocketCharacter->Move(0.02f, 0.0f, DeltaTime);
		m_RocketAnimationComponent->SetAnimation(m_RightAnimName);
		m_RocketAnimationComponent->Play(m_RightAnimName);


	}

	if (m_Time > m_SmokeNextEmitTime)
	{
		m_SmokeProps.Position = m_RocketCharacter->GetSprite()->GetPosition();
		m_ParticleSystem->Emit(m_SmokeProps);
		m_SmokeNextEmitTime += m_SmokeEmitInterval;
	}



}

void SpaceArea::Render()
{
	m_ParticleSystem->OnRender(*m_Camera);


	m_RocketCharacter->OnRender(*m_Camera);

	


}
