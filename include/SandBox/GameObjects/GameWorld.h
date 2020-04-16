#ifndef GAME_WORLD_H
#define GAME_WORLD_H


#include <map>
#include "GameLevel.h"

#include "Space.h"

class GameWorld
{
public:
	GameWorld(float aspectRatio);

	void SetCurrentLevel(std::string& levelName);

	GameLevel* GetCurrentLevel();

	void AddLevel(std::string& levelName,GameLevel * level);

	virtual ~GameWorld();

	void Update(float DeltaTime);

	void Render();

protected:

private:
	std::string m_CurrentLevelName;

	SpaceArea* globalLevel;

	std::map<std::string, GameLevel*> m_Levels;

};




#endif