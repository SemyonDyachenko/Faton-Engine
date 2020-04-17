#ifndef GAME_PARTICLE_SYSTEM_H
#define GAME_PARTICLE_SYSTEM_H

#include <glm/glm.hpp>
#include "../../include/Engine/Engine.h"



class ParticleSystem
{
public:
	ParticleSystem();

	//void Emit(const Props& particleProps);

	void OnUpdate(float DeltaTime);

	void OnRender(Engine::Camera2D& camera);

private:


};



#endif