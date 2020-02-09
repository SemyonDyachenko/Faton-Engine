//
// Created by semyon on 05.12.2019.
//

#include "../../../include/Engine/Physics/BoxCollider2D.h"

namespace Engine {

    namespace Physics {
	

	    BoxCollider2D::BoxCollider2D(Math::FloatRect& bounds) : m_ColliderBounds(bounds)
	    {
	    	
	    }

	    BoxCollider2D::~BoxCollider2D()
	    {
	    }

	    Math::FloatRect& BoxCollider2D::GetBounds() const
	    {
			return m_ColliderBounds;
	    }

	    void BoxCollider2D::Show()
	    {
	    }
    }
}