//
// Created by semyon on 17.12.2019.
//

#ifndef MY_OWN_GAME_VERTEXARRAY_H
#define MY_OWN_GAME_VERTEXARRAY_H


#include <vector>
#include "Drawable.h"
#include "../Math/Math.h"


namespace Engine {


	class Vertex
	{
		Math::Vec3f  position;
		Math::Vec2f	 texcoord;

	public:
		Vertex(Math::Vec3f & pos,Math::Vec2f &texcoord)
		{
			this->position = pos;
			this->texcoord = texcoord;
		}

		inline Math::Vec3f * GetPosition()
		{
			return &this->position;
		}

		inline Math::Vec2f * GetTexCoord()
		{
			return &this->texcoord;
		}
	};

	

	enum class EngineDataType
	{
		FtInt,
		FtFloat,
		Ftsizei,
		FtChar
	};
	
    class VertexArray {
    public:
        virtual ~VertexArray() {}


		virtual void CreateVAO() = 0;
    	
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void AddIndexBuffer(const std::vector<unsigned int> & indices) = 0;

		virtual std::unique_ptr<Drawable> GetDrawable() const = 0;

        virtual void AddVertexBuffer(const std::vector<float> & vertices) = 0;

        static std::shared_ptr<VertexArray> Create();
    };



}

#endif //MY_OWN_GAME_VERTEXARRAY_H
