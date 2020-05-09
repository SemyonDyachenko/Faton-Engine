#include "..\..\..\include\SandBox\GameObjects\Space.h"

//DEMO

SpaceArea::SpaceArea(float aspectRatio, float rocketX, float rocketY)
{
	m_Camera = new Engine::Camera2D(aspectRatio);

	AnimationSpeed = 0.09f;

	m_RocketSmokeSystem = new ParticleSystem();

	m_RocketSmokeProps.Position = { 0.0f, 0.0f };
	m_RocketSmokeProps.Velocity = { -2.0f, 0.0f }, m_RocketSmokeProps.VelocityVar = { 4.0f, 2.0f };
	m_RocketSmokeProps.SizeBirth = 0.2f, m_RocketSmokeProps.SizeDeath = 0.0f, m_RocketSmokeProps.SizeVar = 0.15f;
	m_RocketSmokeProps.BirthColor = { 255.f,0.0f,0.0f, 1.0f };
	m_RocketSmokeProps.DeathColor = { 0.0f, 0.0f, 0.0f, 1.0f };
	m_RocketSmokeProps.LifeTime = 4.0f;

	backgroundTexture = Engine::Texture2D::Create("assets/images/background.jpg");
	background = new Engine::Sprite(0,0,backgroundTexture);
	background1 = new Engine::Sprite(background->GetPosition().x+background->GetSize().x,0,backgroundTexture);
	background->SetSize({ 1920,1080 });
	background1->SetSize({ 1920,1080 });

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


	asteroidTexture = Engine::Texture2D::Create("assets/images/asteroid.png");
	asteroidSprite = new Engine::Sprite(m_RocketCharacter->GetSprite()->GetPosition().x+10, 0, asteroidTexture);
	
	for (int i = 0; i < asteroidCount; i++)
	{
		asteroids.push_back(new Asteroid(45,m_RocketCharacter->GetSprite()->GetPosition().x+10, m_RocketCharacter->GetSprite()->GetPosition().y, { 0.1f,0.1f }));
	}

	for (int i = 0; i < asteroidCount; i++)
	{
		asteroids[i]->AddSpriteComponent(asteroidSprite);
	}

	asteroidMovComponent = new Engine::MovementComponent(*asteroidSprite, 3.0f, 0.15f);

	asteroid = new Asteroid(45, asteroidSprite->GetPosition().x, asteroidSprite->GetPosition().y, { -0.1,-0.05 });
	asteroid->AddMovementComponent(asteroidMovComponent);
	asteroid->AddSpriteComponent(asteroidSprite);
	
}

SpaceArea::~SpaceArea()
{
	
}
  
void SpaceArea::Update(float DeltaTime)
{
	m_Time += DeltaTime;

	m_Camera->OnControl(false);

	m_Camera->Update(DeltaTime);

	m_Camera->SetCameraSpeed(0.015f);
	m_Camera->SetZoomSpeed(0.05f);

	m_Camera->SetZoomFactor(6.0f);

	m_RocketCharacter->OnUpdate(DeltaTime);
	m_RocketMovementComponent->OnUpdate(DeltaTime);
	m_RocketAnimationComponent->OnUpdate(DeltaTime);

	m_RocketCharacter->GetSprite()->ChangeTexture(m_RocketAnimationComponent->GetNowTextureFrame());
	m_RocketCharacter->AddBoxColliderComponent();

	for (int i = 0; i < asteroidCount; i++)
	{
		asteroids[i]->Update(DeltaTime);
	}

	background->SetSize({ 59.2,15.8 });
	background->TransformRecalculate();
	background->TextureRecalculate();

	background1->SetSize({ 59.2,15.8 });
	background1->TransformRecalculate();
	background1->TextureRecalculate();

	//m_Camera->SetPosition({ m_RocketCharacter->GetSprite()->GetPosition().x,m_Camera->GetPosition().y,0 });

	m_RocketCharacter->GetSprite()->SetSize({ 2,1.5 });

	//if (m_RocketCharacter->GetSprite()->GetPosition().x < (m_Camera->GetPosition().x))
	//{
		
		m_Camera->MoveRight(0.003f, DeltaTime);
	//}
//	else if((m_RocketCharacter->GetSprite()->GetPosition().x >= (m_Camera->GetPosition().x)))
	//{
		
 //		m_Camera->SetPosition({ m_RocketCharacter->GetSprite()->GetPosition().x,m_Camera->GetPosition().y,0 });
//	}

	asteroid->Update(DeltaTime);

	m_RocketCharacter->Move(0.025f, 0.0f, DeltaTime);
	m_RocketAnimationComponent->SetAnimation(m_RightAnimName);
	m_RocketAnimationComponent->Play(m_RightAnimName);


	//std::cout << "x: " << m_RocketCharacter->GetSprite()->GetPosition().x << "\n";
	//std::cout << "y: " << m_RocketCharacter->GetSprite()->GetPosition().y << "\n";


	//std::cout << "camera_x: " << m_Camera->GetPosition().x << "\n";
	//std::cout << "camera_y: " << m_Camera->GetPosition().y << "\n";

	std::cout << (m_RocketCharacter->GetSprite()->GetPosition().x > m_Camera->GetPosition().x) << std::endl;

	//if (m_RocketCharacter->GetSprite()->GetPosition().x > (m_Camera->GetPosition().x))
	//{
//		m_Camera->SetPosition({ m_RocketCharacter->GetSprite()->GetPosition().x,m_Camera->GetPosition().y,0 });
	//}



	if (Engine::Input::IsKeyPressed(FATON_KEY_W))
	{
		m_RocketCharacter->Move(0.0f, 0.045f, DeltaTime);
	}
	else if (Engine::Input::IsKeyPressed(FATON_KEY_S))
	{
		m_RocketCharacter->Move(0.0f, -0.045f, DeltaTime);
	}
	else  if (Engine::Input::IsKeyPressed(FATON_KEY_D))
	{
		m_RocketCharacter->Move(0.025f, 0.0f, DeltaTime);
		m_RocketAnimationComponent->SetAnimation(m_RightAnimName);
		m_RocketAnimationComponent->Play(m_RightAnimName);
	}
	else if (Engine::Input::IsKeyPressed(FATON_KEY_A))
	{
		m_RocketCharacter->Move(-0.01f, 0.0f, DeltaTime);
		m_RocketAnimationComponent->SetAnimation(m_RightAnimName);
		m_RocketAnimationComponent->Play(m_RightAnimName);
	}

	if (Engine::Input::GamepadIsConnected(0))
	{

		if (Engine::Input::GamepadGetAxisPosition(0, Engine::Gamepad::Axis::X) > 1)
		{
			m_RocketCharacter->Move(0.025f, 0.0f, DeltaTime);
			m_RocketAnimationComponent->SetAnimation(m_RightAnimName);
			m_RocketAnimationComponent->Play(m_RightAnimName);
		}
		 if (Engine::Input::GamepadGetAxisPosition(0, Engine::Gamepad::Axis::X) < 0)
		{
			m_RocketCharacter->Move(-0.01f, 0.0f, DeltaTime);
			m_RocketAnimationComponent->SetAnimation(m_RightAnimName);
			m_RocketAnimationComponent->Play(m_RightAnimName);
		}
		 if (Engine::Input::GamepadGetAxisPosition(0, Engine::Gamepad::Axis::Y) > 1)
		{
			m_RocketCharacter->Move(0.0f, -0.045f, DeltaTime);
		}
		 if (Engine::Input::GamepadGetAxisPosition(0, Engine::Gamepad::Axis::Y) < 0)
		{
			m_RocketCharacter->Move(0.0f, 0.045f, DeltaTime);
		}
	}

	//if (m_Time > m_SmokeNextEmitTime)
//	{
	//	m_RocketSmokeProps.Position = { m_RocketCharacter->GetSprite()->GetPosition().x,m_RocketCharacter->GetSprite()->GetPosition().y };
	//	m_RocketSmokeSystem->Emit(m_RocketSmokeProps);
//		m_SmokeNextEmitTime += m_SmokeEmitInterval;
	//}

	//m_RocketSmokeSystem->OnUpdate(DeltaTime);

}

void SpaceArea::Render()
{


	
	background->OnRender(*m_Camera);
	background1->OnRender(*m_Camera);


	//Engine::Renderer2D::DrawRect(*m_Camera, { 10.0f,-8 }, { 1920,1080 }, { 0,0,0,1 });
	//m_RocketSmokeSystem->OnRender(*m_Camera);

	for (int i = 0; i < asteroidCount; i++)
	{
		asteroids[i]->GetSprite()->OnRender(*m_Camera);
	}

	//asteroidSprite->OnRender(*m_Camera);

	asteroid->GetSprite()->OnRender(*m_Camera);

	m_RocketCharacter->OnRender(*m_Camera);
}
