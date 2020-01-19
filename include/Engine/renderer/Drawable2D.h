#ifndef ENGINE_DRAWABLE_2D_H
#define ENGINE_DRAWABLE_2D_H


#include "../Math/Math.h"
#include <memory>
#include "Texture.h"




namespace Engine
{
	class Drawable2D
	{
	protected:
		Math::FloatRect bounds;

		std::shared_ptr<Texture2D> m_Texture;

		bool m_Visible;
	public:
		Drawable2D(const Math::Vec2f & position, const Math::Vec2f & size);

		virtual ~Drawable2D();

		virtual void OnRender() const = 0;

		const Math::Vec2f& GetPosition() const;

		const Math::Vec2f& GetSize() const;

		const Math::FloatRect & GetBounds();

		std::shared_ptr<Texture2D> GetTexture();

		bool IsVisible();


		void SetPosition(const Math::Vec2f& position);
		
		void Translate(float x,float y);
		
		void SetSize(const Math::Vec2f& size);

		void SetVisible(bool visible);
		
	};
	
}


#endif