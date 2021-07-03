#include "Batcher.h"

Vertex* Batcher::getVertexes()
{
	return verticies;
}

unsigned int* Batcher::getIndicies()
{
	unsigned int a[] = {
		0, 1, 2,
		2, 3, 0
	};
	return a;
}

unsigned int Batcher::getNumIndicies()
{
	return 6;
}

unsigned int Batcher::getNumElements()
{
	return 4;
}

void Batcher::addGameObject(GameObject* gameObject)
{
	verticies[0] = { {0.0f,0.0f,0.0f},{0.0f,0.0f} };
	verticies[1] = { {0.0f,0.5f,0.0f},{0.0f,1.0f} };
	verticies[2] = { {0.5f,0.5f,0.0f},{1.0f,1.0f} };
	verticies[3] = { {0.5f,0.0f,0.0f},{1.0f,0.0f} };
}
