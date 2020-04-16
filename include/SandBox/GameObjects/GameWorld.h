#ifndef GAME_WORLD_H
#define GAME_WORLD_H


#include <map>
#include "GameLevel.h"

class GameWorld
{
public:
	GameWorld();

	void SetCurrentLevel(std::string& levelName);

	void AddLevel(std::string& levelName,GameLevel * level);

	virtual ~GameWorld();

protected:

private:
	std::string m_CurrentLevelName;
	GameLevel* m_CurrentLevel;


	std::map<std::string, GameLevel*> m_Levels;

};




#endif