//
// Created by semyon on 11.12.2019.
//

#include "../../../include/Engine/Physics/Collision.h"

namespace Engine
{
	namespace Physics
	{
		bool Collision::AABB(const Math::FloatRect& rectA, const Math::FloatRect& rectB)
		{
			if((rectA.x + rectA.w >= rectB.x &&  rectA.y + rectA.h >= rectB.y) || (rectB.x + rectB.w >= rectA.x && rectB.y + rectB.h >= rectA.y))
			{
				return true;
			}

			return false;
		}

	}
}