#pragma once
#include "GameObject.h"
namespace KGLGE {
	class Square : public KGLGE::GameObject {
	public:
		Square(float x, float y, float w, float h, float red, float green, float blue, float alpha);
		// Inherited via GameObject
		virtual void update() override;
		virtual KGLGE::Vertex* getVertexes() override;
		virtual unsigned int getNumVertex() override;
		virtual KGLGE::Triangle* getIndicies(unsigned int offset) override;
		virtual bool respondToKey(unsigned int key) override;
		virtual unsigned int getNumTriangles() override;

	private:
		KGLGE::Vertex m_vertex[4];
		KGLGE::Triangle m_Triangles[2];

	};
}