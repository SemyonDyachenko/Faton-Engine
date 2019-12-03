#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <assert.h>

namespace Textures
{
	enum ID
	{
		Layer1,
		Layer2,
		Layer3,
		Layer4,
		Layer5,
		Layer6,
		PLAYER
	};
}


class TextureHolder
{
private:
	std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
public:

	void load(Textures::ID id, const std::string&filename);

	sf::Texture & get(Textures::ID id);
	
	const sf::Texture & get(Textures::ID id) const;
};

#endif 
