//
// Created by semyon on 11.12.2019.
//

#include "../../../include/Engine/Physics/Collision.h"

namespace Engine
{
	namespace Physics
	{
		bool Collision::Intersects(const Math::FloatRect& rectA, const Math::FloatRect& rectB)
		{
			if((rectA.x + rectA.w) >= rectB.x && ((rectB.x+rectB.w) > rectA.x) && (rectA.y + rectA.h) >= rectB.y && (rectA.y < (rectB.y+rectB.h)))
			{
				return true;
			}

			return false;
		}

	}


	
}