#include "DummyTwo.h"

KGLGE::DummyTwo::DummyTwo()
{
    vert[0] = { {0,0},{0,0.500083f}, 3 };
    vert[1] = { {1,0},{0.5f,0.500083f},3 };
    vert[2] = { {1,-1},{0.5f,0},3 };
    vert[3] = { {0,-1},{0,0},3 };
}

bool KGLGE::DummyTwo::update()
{
    return true;
}
float x = 0;
KGLGE::Vertex* KGLGE::DummyTwo::getVertexes()
{
    return vert;
}

unsigned int KGLGE::DummyTwo::getNumVertex()
{
    return 4;
}

KGLGE::Triangle* KGLGE::DummyTwo::getIndicies(unsigned int offset)
{
    ind[0].index1 = 0 + offset;
    ind[0].index2 = 1 + offset;
    ind[0].index3 = 2 + offset;
    ind[1].index1 = 2 + offset;
    ind[1].index2 = 3 + offset;
    ind[1].index3 = 0 + offset;
    return ind;
}

unsigned int KGLGE::DummyTwo::getNumTriangles()
{
    return 2;
}

bool KGLGE::DummyTwo::respondToKey(unsigned int key)
{
    x += 0.1f;
    return false;
}
