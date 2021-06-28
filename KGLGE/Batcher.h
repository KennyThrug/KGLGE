#pragma once
#include "GameObject.h"
class Batcher {
public:
	float * getVertex();
	float* getVertexAtIndex(unsigned int index);
	unsigned int* getIndicies();
	unsigned int* getIndiciesAtIndex(unsigned int index);
	unsigned int getNumElements();
	void addGameObject(GameObject* gameObject);
	void editGameObject(GameObject* gameObject, int index);
private:
	float* vertex;
	unsigned int * indicies;
	unsigned int numElements;
};