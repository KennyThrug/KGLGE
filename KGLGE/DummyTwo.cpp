#include "DummyTwo.h"

bool KGLGE::DummyTwo::update()
{
    
    return true;
}

KGLGE::Vertex* KGLGE::DummyTwo::getVertexes()
{
    vert[0] = { {0,0},{0,0.500083f}, 3};
    vert[1] = { {1,0},{0.5f,0.500083f},3 };
    vert[2] = { {1,-1},{0.5f,0},3 };
    vert[3] = { {0,-1},{0,0},3 };
    return vert;
}

unsigned int KGLGE::DummyTwo::getNumVertex()
{
    return 4;
}

KGLGE::Triangle* KGLGE::DummyTwo::getIndicies()
{
    ind[0].index1 = 12;
    ind[0].index2 = 13;
    ind[0].index3 = 14;
    ind[1].index1 = 14;
    ind[1].index2 = 15;
    ind[1].index3 = 12;
    return ind;
}

unsigned int KGLGE::DummyTwo::getNumTriangles()
{
    return 2;
}