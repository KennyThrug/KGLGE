#include "../headers/Empty.h"

void KGLGE::Empty::update()
{
}

KGLGE::Vertex* KGLGE::Empty::getVertexes()
{
	return nullptr;
}

unsigned int KGLGE::Empty::getNumVertex()
{
	return 0;
}

KGLGE::Triangle* KGLGE::Empty::getIndicies(unsigned int offset)
{
	return nullptr;
}

bool KGLGE::Empty::respondToKey(unsigned int key)
{
	return false;
}

int KGLGE::Empty::getGameObjectID()
{
	return 4;
}

float KGLGE::Empty::getProperty(int propertyNum)
{
	return 0.0f;
}

int KGLGE::Empty::getPropertyID(int propertyNum)
{
	return 0;
}

int KGLGE::Empty::getPropertySize(int propertyNum)
{
	return 0;
}

int KGLGE::Empty::getNumProperties()
{
	return 0;
}

unsigned int KGLGE::Empty::getNumTriangles()
{
	return 0;
}
