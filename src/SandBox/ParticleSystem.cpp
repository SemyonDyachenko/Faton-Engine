#include "../../include/SandBox/ParticleSystem.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/compatibility.hpp>


ParticleSystem::ParticleSystem()
{
	m_ParticlePool.resize(1000);
}

void ParticleSystem::OnUpdate(float DeltaTime)
{
	for (auto& particle : m_ParticlePool)
	{
		if (!particle.Active)
			continue;
		if (particle.LifeRemaining <= 0.0f)
		{
			particle.Active = false;
			continue;
		}

		particle.LifeRemaining -= DeltaTime;
		particle.Position += particle.Velocity * (float)DeltaTime;
		particle.Rotation += 0.01f * DeltaTime;
	}


}

void ParticleSystem::OnRender(Engine::Camera2D& camera)
{
	for (auto& particle : m_ParticlePool)
	{
		if (!particle.Active)
			continue;

		float life = particle.LifeRemaining / particle.LifeTime;
		glm::vec4 color = glm::lerp(particle.DeathColor, particle.BirthColor, life);
		color.a = color.a * life;

		float size = glm::lerp(particle.SizeDeath, particle.SizeBirth, life);
		Engine::Renderer2D::DrawLight(camera, { particle.Position.x,particle.Position.y }, { size, size }, particle.Rotation, { color.x/255.f,color.y/255.f,color.z/255.f,color.w });
	}
}

void ParticleSystem::Emit(const ParticleProps& particleProps)
{

	Particle& particle = m_ParticlePool[m_PoolIndex];
	particle.Active = true;
	particle.Position = particleProps.Position;
	particle.Rotation = Random::Float() * 2.0f * glm::pi<float>();

	// Velocity
	particle.Velocity = particleProps.Velocity;
	particle.Velocity.x += particleProps.VelocityVar.x * (Random::Float() - 0.5f);
	particle.Velocity.y += particleProps.VelocityVar.y * (Random::Float() - 0.5f);

	// Color
	particle.BirthColor = particleProps.BirthColor;
	particle.DeathColor = particleProps.DeathColor;

	// Size
	particle.SizeBirth = particleProps.SizeBirth + particleProps.SizeVar * (Random::Float() - 0.5f);
	particle.SizeDeath = particleProps.SizeDeath;

	// Life
	particle.LifeTime = particleProps.LifeTime;
	particle.LifeRemaining = particleProps.LifeTime;

	m_PoolIndex = --m_PoolIndex % m_ParticlePool.size();
}