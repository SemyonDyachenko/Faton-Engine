#ifndef ENGINE_OBJLOADER_H
#define ENGINE_OBJLOADER_H

#include <vector>
#include "../Math/Math.h"
#include <sstream>
#include <glm/glm.hpp>
#include "../3dRenderer/Mesh.h"
#include <array>

namespace Engine
{

		

	class OBJLoader
	{
	public:

		static void Load(const char * path);
	};
	
}


#endif