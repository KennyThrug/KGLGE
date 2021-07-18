#pragma once
#include "GameObject.h"
namespace KGLGE {
	class DummyGO : public GameObject {
	public:
		bool update() override;
		Vertex* getVertexes() override;
		unsigned int getNumVertex() override;
		Triangle* getIndicies() override;
		unsigned int getNumTriangles() override;

	private:
		KGLGE::Vertex vert[12];
		KGLGE::Triangle indicies[18];
	};
}