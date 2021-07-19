#include "Sprite.h"

bool KGLGE::Sprite::update()
{
	return false;
}

KGLGE::Vertex* KGLGE::Sprite::getVertexes()
{
	return nullptr;
}

unsigned int KGLGE::Sprite::getNumVertex()
{
	return 0;
}

KGLGE::Triangle* KGLGE::Sprite::getIndicies(unsigned int offset)
{
	return nullptr;
}

unsigned int KGLGE::Sprite::getNumTriangles()
{
	return 0;
}

bool KGLGE::Sprite::respondToKey(unsigned int key)
{
	return false;
}
