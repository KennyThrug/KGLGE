#include "DummyGO.h"

void KGLGE::DummyGO::update()
{
}

KGLGE::Vertex* KGLGE::DummyGO::getVertexes()
{
	float vertecies[] = {
		0,1,0,1,1,
		1,1,1,1,1,
		1,0,1,0,1,
		0,0,0,0,1,

		0,-1,0,1,0,
		-1,-1,1,1,0,
		-1,0,1,0,0,
		0,0,0,0,0,

		-1,1,0,1,2,
		0,1,1,1,2,
		0,0,1,0,2,
		-1,0,0,0,2
	};
	for (int i = 0; i < 12; i++) {
		int te = i * 5;
		vert[i] = {
			vertecies[te],
			vertecies[te + 1],
			vertecies[te + 2],
			vertecies[te + 3],
			vertecies[te + 4]
		};
	}
	return vert;
}

unsigned int KGLGE::DummyGO::getNumVertex()
{
	return 12;
}

KGLGE::Triangle* KGLGE::DummyGO::getIndicies(unsigned int offset)
{
	indicies[0].index1 = 0 + offset;
	indicies[0].index2 = 1 + offset;
	indicies[0].index3 = 2 + offset;

	indicies[1].index1 = 2 + offset;
	indicies[1].index2 = 3 + offset;
	indicies[1].index3 = 0 + offset;

	indicies[2].index1 = 4 + offset;
	indicies[2].index2 = 5 + offset;
	indicies[2].index3 = 6 + offset;


	indicies[3].index1 = 6;
	indicies[3].index2 = 7;
	indicies[3].index3 = 4;

	indicies[4].index1 = 8; 
	indicies[4].index2 = 9;
	indicies[4].index3 = 10;

	indicies[5].index1 = 10;
	indicies[5].index2 = 11;
	indicies[5].index3 = 8;
	return indicies;
}

unsigned int KGLGE::DummyGO::getNumTriangles()
{
	return 6;
}

bool KGLGE::DummyGO::respondToKey(unsigned int key)
{
	return false;
}
