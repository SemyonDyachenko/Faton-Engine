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
			if((rectA.x + rectA.w) >= rectB.x && (rectA.y + rectA.h) >= rectB.y)
			{
				return true;
			}

			return false;
		}

	}


	
}