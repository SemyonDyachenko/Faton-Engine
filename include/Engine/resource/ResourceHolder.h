#ifndef RESOURCE_HOLDER_H
#define RESOURCE HOLDER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <assert.h>

template<typename  Resource,typename Identifier>
class ResourceHolder
{
private:
	std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
public:
	void load(Identifier id, const std::string&filename);
	bool loadFromFile(const std::string& filename, sf::Shader::Type type);
	
	bool loadFromFile(const std::string& vertexShaderFilename,const std::string& fragmentShaderFilename);

	template <typename Parameter>
	void load(Identifier id, const std::string& filename,const Parameter& secondParam);
	
	Resource& get(Identifier id);

	const Resource& get(Identifier id) const;
};




#endif 
