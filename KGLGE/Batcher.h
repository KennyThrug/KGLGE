#pragma once
#include <array>
#include "GameObject.h"
struct Positions {
	float x;
	float y;
	float z;
};
struct TexCoords {
	float x;
	float y;
};
struct Vertex {
	Positions positions;
	TexCoords texCoords;
};

class Batcher {
public:
	Vertex* getVertexes();
	Vertex * getVertexAtIndex(unsigned int index);
	unsigned int* getIndicies();
	unsigned int getNumIndicies();
	unsigned int* getIndiciesAtIndex(unsigned int index);
	unsigned int getNumElements();
	void addGameObject(GameObject* gameObject);
	void editGameObject(GameObject* gameObject, int index);
private:
	unsigned int * indicies;
	unsigned int numElements;
	Vertex verticies[1000];

	void reCheckVerticies();
};