#ifndef GAME_WORLD_H
#define GAME_WORLD_H


#include <map>
#include "GameLevel.h"

class GameWorld
{
public:
	GameWorld();

	void SetCurrentLevel(std::string& levelName);

	GameLevel* GetCurrentLevel();

	void AddLevel(std::string& levelName,GameLevel * level);

	virtual ~GameWorld();

	void Update(float DeltaTime);

	void Render();

protected:

private:
	std::string m_CurrentLevelName;

	std::map<std::string, GameLevel*> m_Levels;

};




#endif