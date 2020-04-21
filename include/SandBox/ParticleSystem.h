#ifndef GAME_PARTICLE_SYSTEM_H
#define GAME_PARTICLE_SYSTEM_H

#include <glm/glm.hpp>
#include "../../include/Engine/Engine.h"
#include "GameUtils/Random.h"

struct ParticleProps
{
	glm::vec2 Position;
	glm::vec2 Velocity, VelocityVar;
	glm::vec4 BirthColor, DeathColor;
	float SizeBirth, SizeDeath, SizeVar;
	float LifeTime = 1.0f;
};


class ParticleSystem
{
public:
	ParticleSystem();

	void Emit(const ParticleProps& particleProps);

	void OnUpdate(float DeltaTime);

	void OnRender(Engine::Camera2D& camera);

private:

	struct Particle
	{
		glm::vec2 Position;
		glm::vec2 Velocity;
		glm::vec4 BirthColor, DeathColor;
		float Rotation = 0.0f;
		float SizeBirth, SizeDeath;

		float LifeTime = 1.0f;
		float LifeRemaining = 0.0f;
		
		bool Active = false;
	};

	std::vector<Particle> m_ParticlePool;
	unsigned int m_PoolIndex = 999;

};



#endif