//
// Created by semyon on 11.12.2019.
//

#include "../../../include/Engine/Physics/Collision.h"

namespace Engine
{
	namespace Physics
	{
		bool Collision::Intersects(BoxCollider2D& colliderA, BoxCollider2D & colliderB)
		{
			if((colliderA.GetBounds().x + colliderA.GetBounds().w) >= colliderB.GetBounds().x && ((colliderB.GetBounds().x+ colliderB.GetBounds().w) > colliderA.GetBounds().x) && (colliderA.GetBounds().y + colliderA.GetBounds().h) >= colliderB.GetBounds().y && (colliderA.GetBounds().y < (colliderB.GetBounds().y+ colliderB.GetBounds().h)))
			{
				return true;
			}

			return false;
		}

	}


	
}